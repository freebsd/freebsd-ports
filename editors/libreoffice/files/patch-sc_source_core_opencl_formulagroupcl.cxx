https://bugs.gentoo.org/713574
https://bugs.documentfoundation.org/show_bug.cgi?id=131591

--- sc/source/core/opencl/formulagroupcl.cxx.orig	2020-03-11 16:18:35 UTC
+++ sc/source/core/opencl/formulagroupcl.cxx
@@ -1026,8 +1026,6 @@ class DynamicKernelMixedArgument : public VectorRef (p
 /// Handling a Double Vector that is used as a sliding window input
 /// to either a sliding window average or sum-of-products
 /// Generate a sequential loop for reductions
-class OpAverage;
-class OpCount;
 
 template<class Base>
 class DynamicKernelSlidingArgument : public Base
@@ -1335,186 +1333,8 @@ class ParallelReductionVectorRef : public Base (public
     }
 
     /// Emit the definition for the auxiliary reduction kernel
-    virtual void GenSlidingWindowFunction( std::stringstream& ss )
-    {
-        if (!dynamic_cast<OpAverage*>(mpCodeGen.get()))
-        {
-            std::string name = Base::GetName();
-            ss << "__kernel void " << name;
-            ss << "_reduction(__global double* A, "
-                "__global double *result,int arrayLength,int windowSize){\n";
-            ss << "    double tmp, current_result =" <<
-                mpCodeGen->GetBottom();
-            ss << ";\n";
-            ss << "    int writePos = get_group_id(1);\n";
-            ss << "    int lidx = get_local_id(0);\n";
-            ss << "    __local double shm_buf[256];\n";
-            if (mpDVR->IsStartFixed())
-                ss << "    int offset = 0;\n";
-            else // if (!mpDVR->IsStartFixed())
-                ss << "    int offset = get_group_id(1);\n";
-            if (mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
-                ss << "    int end = windowSize;\n";
-            else if (!mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
-                ss << "    int end = offset + windowSize;\n";
-            else if (mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
-                ss << "    int end = windowSize + get_group_id(1);\n";
-            else if (!mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
-                ss << "    int end = windowSize;\n";
-            ss << "    end = min(end, arrayLength);\n";
+    virtual void GenSlidingWindowFunction( std::stringstream& ss );
 
-            ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    int loop = arrayLength/512 + 1;\n";
-            ss << "    for (int l=0; l<loop; l++){\n";
-            ss << "    tmp = " << mpCodeGen->GetBottom() << ";\n";
-            ss << "    int loopOffset = l*512;\n";
-            ss << "    if((loopOffset + lidx + offset + 256) < end) {\n";
-            ss << "        tmp = legalize(" << mpCodeGen->Gen2(
-                "A[loopOffset + lidx + offset]", "tmp") << ", tmp);\n";
-            ss << "        tmp = legalize(" << mpCodeGen->Gen2(
-                "A[loopOffset + lidx + offset + 256]", "tmp") << ", tmp);\n";
-            ss << "    } else if ((loopOffset + lidx + offset) < end)\n";
-            ss << "        tmp = legalize(" << mpCodeGen->Gen2(
-                "A[loopOffset + lidx + offset]", "tmp") << ", tmp);\n";
-            ss << "    shm_buf[lidx] = tmp;\n";
-            ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    for (int i = 128; i >0; i/=2) {\n";
-            ss << "        if (lidx < i)\n";
-            ss << "            shm_buf[lidx] = ";
-            // Special case count
-            if (dynamic_cast<OpCount*>(mpCodeGen.get()))
-                ss << "shm_buf[lidx] + shm_buf[lidx + i];\n";
-            else
-                ss << mpCodeGen->Gen2("shm_buf[lidx]", "shm_buf[lidx + i]") << ";\n";
-            ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    }\n";
-            ss << "        if (lidx == 0)\n";
-            ss << "            current_result =";
-            if (dynamic_cast<OpCount*>(mpCodeGen.get()))
-                ss << "current_result + shm_buf[0]";
-            else
-                ss << mpCodeGen->Gen2("current_result", "shm_buf[0]");
-            ss << ";\n";
-            ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    }\n";
-            ss << "    if (lidx == 0)\n";
-            ss << "        result[writePos] = current_result;\n";
-            ss << "}\n";
-        }
-        else
-        {
-            std::string name = Base::GetName();
-            /*sum reduction*/
-            ss << "__kernel void " << name << "_sum";
-            ss << "_reduction(__global double* A, "
-                "__global double *result,int arrayLength,int windowSize){\n";
-            ss << "    double tmp, current_result =" <<
-                mpCodeGen->GetBottom();
-            ss << ";\n";
-            ss << "    int writePos = get_group_id(1);\n";
-            ss << "    int lidx = get_local_id(0);\n";
-            ss << "    __local double shm_buf[256];\n";
-            if (mpDVR->IsStartFixed())
-                ss << "    int offset = 0;\n";
-            else // if (!mpDVR->IsStartFixed())
-                ss << "    int offset = get_group_id(1);\n";
-            if (mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
-                ss << "    int end = windowSize;\n";
-            else if (!mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
-                ss << "    int end = offset + windowSize;\n";
-            else if (mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
-                ss << "    int end = windowSize + get_group_id(1);\n";
-            else if (!mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
-                ss << "    int end = windowSize;\n";
-            ss << "    end = min(end, arrayLength);\n";
-            ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    int loop = arrayLength/512 + 1;\n";
-            ss << "    for (int l=0; l<loop; l++){\n";
-            ss << "    tmp = " << mpCodeGen->GetBottom() << ";\n";
-            ss << "    int loopOffset = l*512;\n";
-            ss << "    if((loopOffset + lidx + offset + 256) < end) {\n";
-            ss << "        tmp = legalize(";
-            ss << "(A[loopOffset + lidx + offset]+ tmp)";
-            ss << ", tmp);\n";
-            ss << "        tmp = legalize((A[loopOffset + lidx + offset + 256]+ tmp)";
-            ss << ", tmp);\n";
-            ss << "    } else if ((loopOffset + lidx + offset) < end)\n";
-            ss << "        tmp = legalize((A[loopOffset + lidx + offset] + tmp)";
-            ss << ", tmp);\n";
-            ss << "    shm_buf[lidx] = tmp;\n";
-            ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    for (int i = 128; i >0; i/=2) {\n";
-            ss << "        if (lidx < i)\n";
-            ss << "            shm_buf[lidx] = ";
-            ss << "shm_buf[lidx] + shm_buf[lidx + i];\n";
-            ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    }\n";
-            ss << "        if (lidx == 0)\n";
-            ss << "            current_result =";
-            ss << "current_result + shm_buf[0]";
-            ss << ";\n";
-            ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    }\n";
-            ss << "    if (lidx == 0)\n";
-            ss << "        result[writePos] = current_result;\n";
-            ss << "}\n";
-            /*count reduction*/
-            ss << "__kernel void " << name << "_count";
-            ss << "_reduction(__global double* A, "
-                "__global double *result,int arrayLength,int windowSize){\n";
-            ss << "    double tmp, current_result =" <<
-                mpCodeGen->GetBottom();
-            ss << ";\n";
-            ss << "    int writePos = get_group_id(1);\n";
-            ss << "    int lidx = get_local_id(0);\n";
-            ss << "    __local double shm_buf[256];\n";
-            if (mpDVR->IsStartFixed())
-                ss << "    int offset = 0;\n";
-            else // if (!mpDVR->IsStartFixed())
-                ss << "    int offset = get_group_id(1);\n";
-            if (mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
-                ss << "    int end = windowSize;\n";
-            else if (!mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
-                ss << "    int end = offset + windowSize;\n";
-            else if (mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
-                ss << "    int end = windowSize + get_group_id(1);\n";
-            else if (!mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
-                ss << "    int end = windowSize;\n";
-            ss << "    end = min(end, arrayLength);\n";
-            ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    int loop = arrayLength/512 + 1;\n";
-            ss << "    for (int l=0; l<loop; l++){\n";
-            ss << "    tmp = " << mpCodeGen->GetBottom() << ";\n";
-            ss << "    int loopOffset = l*512;\n";
-            ss << "    if((loopOffset + lidx + offset + 256) < end) {\n";
-            ss << "        tmp = legalize((isnan(A[loopOffset + lidx + offset])?tmp:tmp+1.0)";
-            ss << ", tmp);\n";
-            ss << "        tmp = legalize((isnan(A[loopOffset + lidx + offset+256])?tmp:tmp+1.0)";
-            ss << ", tmp);\n";
-            ss << "    } else if ((loopOffset + lidx + offset) < end)\n";
-            ss << "        tmp = legalize((isnan(A[loopOffset + lidx + offset])?tmp:tmp+1.0)";
-            ss << ", tmp);\n";
-            ss << "    shm_buf[lidx] = tmp;\n";
-            ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    for (int i = 128; i >0; i/=2) {\n";
-            ss << "        if (lidx < i)\n";
-            ss << "            shm_buf[lidx] = ";
-            ss << "shm_buf[lidx] + shm_buf[lidx + i];\n";
-            ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    }\n";
-            ss << "        if (lidx == 0)\n";
-            ss << "            current_result =";
-            ss << "current_result + shm_buf[0];";
-            ss << ";\n";
-            ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
-            ss << "    }\n";
-            ss << "    if (lidx == 0)\n";
-            ss << "        result[writePos] = current_result;\n";
-            ss << "}\n";
-        }
-
-    }
-
     virtual std::string GenSlidingWindowDeclRef( bool ) const
     {
         std::stringstream ss;
@@ -1527,195 +1347,10 @@ class ParallelReductionVectorRef : public Base (public
 
     /// Controls how the elements in the DoubleVectorRef are traversed
     size_t GenReductionLoopHeader(
-        std::stringstream& ss, int nResultSize, bool& needBody )
-    {
-        assert(mpDVR);
-        size_t nCurWindowSize = mpDVR->GetRefRowSize();
-        std::string temp = Base::GetName() + "[gid0]";
-        ss << "tmp = ";
-        // Special case count
-        if (dynamic_cast<OpAverage*>(mpCodeGen.get()))
-        {
-            ss << mpCodeGen->Gen2(temp, "tmp") << ";\n";
-            ss << "nCount = nCount-1;\n";
-            ss << "nCount = nCount +"; /*re-assign nCount from count reduction*/
-            ss << Base::GetName() << "[gid0+" << nResultSize << "]" << ";\n";
-        }
-        else if (dynamic_cast<OpCount*>(mpCodeGen.get()))
-            ss << temp << "+ tmp";
-        else
-            ss << mpCodeGen->Gen2(temp, "tmp");
-        ss << ";\n\t";
-        needBody = false;
-        return nCurWindowSize;
-    }
+        std::stringstream& ss, int nResultSize, bool& needBody );
 
-    virtual size_t Marshal( cl_kernel k, int argno, int w, cl_program mpProgram )
-    {
-        assert(Base::mpClmem == nullptr);
+    virtual size_t Marshal( cl_kernel k, int argno, int w, cl_program mpProgram );
 
-        openclwrapper::KernelEnv kEnv;
-        openclwrapper::setKernelEnv(&kEnv);
-        cl_int err;
-        size_t nInput = mpDVR->GetArrayLength();
-        size_t nCurWindowSize = mpDVR->GetRefRowSize();
-        // create clmem buffer
-        if (mpDVR->GetArrays()[Base::mnIndex].mpNumericArray == nullptr)
-            throw Unhandled(__FILE__, __LINE__);
-        double* pHostBuffer = const_cast<double*>(
-            mpDVR->GetArrays()[Base::mnIndex].mpNumericArray);
-        size_t szHostBuffer = nInput * sizeof(double);
-        Base::mpClmem = clCreateBuffer(kEnv.mpkContext,
-            cl_mem_flags(CL_MEM_READ_ONLY) | CL_MEM_USE_HOST_PTR,
-            szHostBuffer,
-            pHostBuffer, &err);
-        SAL_INFO("sc.opencl", "Created buffer " << Base::mpClmem << " size " << nInput << "*" << sizeof(double) << "=" << szHostBuffer << " using host buffer " << pHostBuffer);
-
-        mpClmem2 = clCreateBuffer(kEnv.mpkContext,
-            CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR,
-            sizeof(double) * w, nullptr, nullptr);
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clCreateBuffer", err, __FILE__, __LINE__);
-        SAL_INFO("sc.opencl", "Created buffer " << mpClmem2 << " size " << sizeof(double) << "*" << w << "=" << (sizeof(double)*w));
-
-        // reproduce the reduction function name
-        std::string kernelName;
-        if (!dynamic_cast<OpAverage*>(mpCodeGen.get()))
-            kernelName = Base::GetName() + "_reduction";
-        else
-            kernelName = Base::GetName() + "_sum_reduction";
-        cl_kernel redKernel = clCreateKernel(mpProgram, kernelName.c_str(), &err);
-        if (err != CL_SUCCESS)
-            throw OpenCLError("clCreateKernel", err, __FILE__, __LINE__);
-        SAL_INFO("sc.opencl", "Created kernel " << redKernel << " with name " << kernelName << " in program " << mpProgram);
-
-        // set kernel arg of reduction kernel
-        // TODO(Wei Wei): use unique name for kernel
-        cl_mem buf = Base::GetCLBuffer();
-        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 0 << ": cl_mem: " << buf);
-        err = clSetKernelArg(redKernel, 0, sizeof(cl_mem),
-            static_cast<void*>(&buf));
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 1 << ": cl_mem: " << mpClmem2);
-        err = clSetKernelArg(redKernel, 1, sizeof(cl_mem), &mpClmem2);
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 2 << ": cl_int: " << nInput);
-        err = clSetKernelArg(redKernel, 2, sizeof(cl_int), static_cast<void*>(&nInput));
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 3 << ": cl_int: " << nCurWindowSize);
-        err = clSetKernelArg(redKernel, 3, sizeof(cl_int), static_cast<void*>(&nCurWindowSize));
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-        // set work group size and execute
-        size_t global_work_size[] = { 256, static_cast<size_t>(w) };
-        size_t const local_work_size[] = { 256, 1 };
-        SAL_INFO("sc.opencl", "Enqueing kernel " << redKernel);
-        err = clEnqueueNDRangeKernel(kEnv.mpkCmdQueue, redKernel, 2, nullptr,
-            global_work_size, local_work_size, 0, nullptr, nullptr);
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clEnqueueNDRangeKernel", err, __FILE__, __LINE__);
-        err = clFinish(kEnv.mpkCmdQueue);
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clFinish", err, __FILE__, __LINE__);
-        if (dynamic_cast<OpAverage*>(mpCodeGen.get()))
-        {
-            /*average need more reduction kernel for count computing*/
-            std::unique_ptr<double[]> pAllBuffer(new double[2 * w]);
-            double* resbuf = static_cast<double*>(clEnqueueMapBuffer(kEnv.mpkCmdQueue,
-                mpClmem2,
-                CL_TRUE, CL_MAP_READ, 0,
-                sizeof(double) * w, 0, nullptr, nullptr,
-                &err));
-            if (err != CL_SUCCESS)
-                throw OpenCLError("clEnqueueMapBuffer", err, __FILE__, __LINE__);
-
-            for (int i = 0; i < w; i++)
-                pAllBuffer[i] = resbuf[i];
-            err = clEnqueueUnmapMemObject(kEnv.mpkCmdQueue, mpClmem2, resbuf, 0, nullptr, nullptr);
-            if (err != CL_SUCCESS)
-                throw OpenCLError("clEnqueueUnmapMemObject", err, __FILE__, __LINE__);
-
-            kernelName = Base::GetName() + "_count_reduction";
-            redKernel = clCreateKernel(mpProgram, kernelName.c_str(), &err);
-            if (err != CL_SUCCESS)
-                throw OpenCLError("clCreateKernel", err, __FILE__, __LINE__);
-            SAL_INFO("sc.opencl", "Created kernel " << redKernel << " with name " << kernelName << " in program " << mpProgram);
-
-            // set kernel arg of reduction kernel
-            buf = Base::GetCLBuffer();
-            SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 0 << ": cl_mem: " << buf);
-            err = clSetKernelArg(redKernel, 0, sizeof(cl_mem),
-                static_cast<void*>(&buf));
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-            SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 1 << ": cl_mem: " << mpClmem2);
-            err = clSetKernelArg(redKernel, 1, sizeof(cl_mem), &mpClmem2);
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-            SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 2 << ": cl_int: " << nInput);
-            err = clSetKernelArg(redKernel, 2, sizeof(cl_int), static_cast<void*>(&nInput));
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-            SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 3 << ": cl_int: " << nCurWindowSize);
-            err = clSetKernelArg(redKernel, 3, sizeof(cl_int), static_cast<void*>(&nCurWindowSize));
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-
-            // set work group size and execute
-            size_t global_work_size1[] = { 256, static_cast<size_t>(w) };
-            size_t const local_work_size1[] = { 256, 1 };
-            SAL_INFO("sc.opencl", "Enqueing kernel " << redKernel);
-            err = clEnqueueNDRangeKernel(kEnv.mpkCmdQueue, redKernel, 2, nullptr,
-                global_work_size1, local_work_size1, 0, nullptr, nullptr);
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clEnqueueNDRangeKernel", err, __FILE__, __LINE__);
-            err = clFinish(kEnv.mpkCmdQueue);
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clFinish", err, __FILE__, __LINE__);
-            resbuf = static_cast<double*>(clEnqueueMapBuffer(kEnv.mpkCmdQueue,
-                mpClmem2,
-                CL_TRUE, CL_MAP_READ, 0,
-                sizeof(double) * w, 0, nullptr, nullptr,
-                &err));
-            if (err != CL_SUCCESS)
-                throw OpenCLError("clEnqueueMapBuffer", err, __FILE__, __LINE__);
-            for (int i = 0; i < w; i++)
-                pAllBuffer[i + w] = resbuf[i];
-            err = clEnqueueUnmapMemObject(kEnv.mpkCmdQueue, mpClmem2, resbuf, 0, nullptr, nullptr);
-            // FIXME: Is it intentional to not throw an OpenCLError even if the clEnqueueUnmapMemObject() fails?
-            if (CL_SUCCESS != err)
-                SAL_WARN("sc.opencl", "clEnqueueUnmapMemObject failed: " << openclwrapper::errorString(err));
-            if (mpClmem2)
-            {
-                err = clReleaseMemObject(mpClmem2);
-                SAL_WARN_IF(err != CL_SUCCESS, "sc.opencl", "clReleaseMemObject failed: " << openclwrapper::errorString(err));
-                mpClmem2 = nullptr;
-            }
-            mpClmem2 = clCreateBuffer(kEnv.mpkContext,
-                cl_mem_flags(CL_MEM_READ_WRITE) | CL_MEM_COPY_HOST_PTR,
-                w * sizeof(double) * 2, pAllBuffer.get(), &err);
-            if (CL_SUCCESS != err)
-                throw OpenCLError("clCreateBuffer", err, __FILE__, __LINE__);
-            SAL_INFO("sc.opencl", "Created buffer " << mpClmem2 << " size " << w << "*" << sizeof(double) << "=" << (w*sizeof(double)) << " copying host buffer " << pAllBuffer.get());
-        }
-        // set kernel arg
-        SAL_INFO("sc.opencl", "Kernel " << k << " arg " << argno << ": cl_mem: " << mpClmem2);
-        err = clSetKernelArg(k, argno, sizeof(cl_mem), &mpClmem2);
-        if (CL_SUCCESS != err)
-            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
-        return 1;
-    }
-
     ~ParallelReductionVectorRef()
     {
         if (mpClmem2)
@@ -2324,6 +1959,379 @@ struct SumIfsArgs
     cl_mem mCLMem;
     double mConst;
 };
+}
+
+template<class Base>
+void ParallelReductionVectorRef<Base>::GenSlidingWindowFunction( std::stringstream& ss )
+{
+    if (!dynamic_cast<OpAverage*>(mpCodeGen.get()))
+    {
+        std::string name = Base::GetName();
+        ss << "__kernel void " << name;
+        ss << "_reduction(__global double* A, "
+            "__global double *result,int arrayLength,int windowSize){\n";
+        ss << "    double tmp, current_result =" <<
+            mpCodeGen->GetBottom();
+        ss << ";\n";
+        ss << "    int writePos = get_group_id(1);\n";
+        ss << "    int lidx = get_local_id(0);\n";
+        ss << "    __local double shm_buf[256];\n";
+        if (mpDVR->IsStartFixed())
+            ss << "    int offset = 0;\n";
+        else // if (!mpDVR->IsStartFixed())
+            ss << "    int offset = get_group_id(1);\n";
+        if (mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
+            ss << "    int end = windowSize;\n";
+        else if (!mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
+            ss << "    int end = offset + windowSize;\n";
+        else if (mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
+            ss << "    int end = windowSize + get_group_id(1);\n";
+        else if (!mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
+            ss << "    int end = windowSize;\n";
+        ss << "    end = min(end, arrayLength);\n";
+
+        ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    int loop = arrayLength/512 + 1;\n";
+        ss << "    for (int l=0; l<loop; l++){\n";
+        ss << "    tmp = " << mpCodeGen->GetBottom() << ";\n";
+        ss << "    int loopOffset = l*512;\n";
+        ss << "    if((loopOffset + lidx + offset + 256) < end) {\n";
+        ss << "        tmp = legalize(" << mpCodeGen->Gen2(
+            "A[loopOffset + lidx + offset]", "tmp") << ", tmp);\n";
+        ss << "        tmp = legalize(" << mpCodeGen->Gen2(
+            "A[loopOffset + lidx + offset + 256]", "tmp") << ", tmp);\n";
+        ss << "    } else if ((loopOffset + lidx + offset) < end)\n";
+        ss << "        tmp = legalize(" << mpCodeGen->Gen2(
+            "A[loopOffset + lidx + offset]", "tmp") << ", tmp);\n";
+        ss << "    shm_buf[lidx] = tmp;\n";
+        ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    for (int i = 128; i >0; i/=2) {\n";
+        ss << "        if (lidx < i)\n";
+        ss << "            shm_buf[lidx] = ";
+        // Special case count
+        if (dynamic_cast<OpCount*>(mpCodeGen.get()))
+            ss << "shm_buf[lidx] + shm_buf[lidx + i];\n";
+        else
+            ss << mpCodeGen->Gen2("shm_buf[lidx]", "shm_buf[lidx + i]") << ";\n";
+        ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    }\n";
+        ss << "        if (lidx == 0)\n";
+        ss << "            current_result =";
+        if (dynamic_cast<OpCount*>(mpCodeGen.get()))
+            ss << "current_result + shm_buf[0]";
+        else
+            ss << mpCodeGen->Gen2("current_result", "shm_buf[0]");
+        ss << ";\n";
+        ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    }\n";
+        ss << "    if (lidx == 0)\n";
+        ss << "        result[writePos] = current_result;\n";
+        ss << "}\n";
+    }
+    else
+    {
+        std::string name = Base::GetName();
+        /*sum reduction*/
+        ss << "__kernel void " << name << "_sum";
+        ss << "_reduction(__global double* A, "
+            "__global double *result,int arrayLength,int windowSize){\n";
+        ss << "    double tmp, current_result =" <<
+            mpCodeGen->GetBottom();
+        ss << ";\n";
+        ss << "    int writePos = get_group_id(1);\n";
+        ss << "    int lidx = get_local_id(0);\n";
+        ss << "    __local double shm_buf[256];\n";
+        if (mpDVR->IsStartFixed())
+            ss << "    int offset = 0;\n";
+        else // if (!mpDVR->IsStartFixed())
+            ss << "    int offset = get_group_id(1);\n";
+        if (mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
+            ss << "    int end = windowSize;\n";
+        else if (!mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
+            ss << "    int end = offset + windowSize;\n";
+        else if (mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
+            ss << "    int end = windowSize + get_group_id(1);\n";
+        else if (!mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
+            ss << "    int end = windowSize;\n";
+        ss << "    end = min(end, arrayLength);\n";
+        ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    int loop = arrayLength/512 + 1;\n";
+        ss << "    for (int l=0; l<loop; l++){\n";
+        ss << "    tmp = " << mpCodeGen->GetBottom() << ";\n";
+        ss << "    int loopOffset = l*512;\n";
+        ss << "    if((loopOffset + lidx + offset + 256) < end) {\n";
+        ss << "        tmp = legalize(";
+        ss << "(A[loopOffset + lidx + offset]+ tmp)";
+        ss << ", tmp);\n";
+        ss << "        tmp = legalize((A[loopOffset + lidx + offset + 256]+ tmp)";
+        ss << ", tmp);\n";
+        ss << "    } else if ((loopOffset + lidx + offset) < end)\n";
+        ss << "        tmp = legalize((A[loopOffset + lidx + offset] + tmp)";
+        ss << ", tmp);\n";
+        ss << "    shm_buf[lidx] = tmp;\n";
+        ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    for (int i = 128; i >0; i/=2) {\n";
+        ss << "        if (lidx < i)\n";
+        ss << "            shm_buf[lidx] = ";
+        ss << "shm_buf[lidx] + shm_buf[lidx + i];\n";
+        ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    }\n";
+        ss << "        if (lidx == 0)\n";
+        ss << "            current_result =";
+        ss << "current_result + shm_buf[0]";
+        ss << ";\n";
+        ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    }\n";
+        ss << "    if (lidx == 0)\n";
+        ss << "        result[writePos] = current_result;\n";
+        ss << "}\n";
+        /*count reduction*/
+        ss << "__kernel void " << name << "_count";
+        ss << "_reduction(__global double* A, "
+            "__global double *result,int arrayLength,int windowSize){\n";
+        ss << "    double tmp, current_result =" <<
+            mpCodeGen->GetBottom();
+        ss << ";\n";
+        ss << "    int writePos = get_group_id(1);\n";
+        ss << "    int lidx = get_local_id(0);\n";
+        ss << "    __local double shm_buf[256];\n";
+        if (mpDVR->IsStartFixed())
+            ss << "    int offset = 0;\n";
+        else // if (!mpDVR->IsStartFixed())
+            ss << "    int offset = get_group_id(1);\n";
+        if (mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
+            ss << "    int end = windowSize;\n";
+        else if (!mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
+            ss << "    int end = offset + windowSize;\n";
+        else if (mpDVR->IsStartFixed() && !mpDVR->IsEndFixed())
+            ss << "    int end = windowSize + get_group_id(1);\n";
+        else if (!mpDVR->IsStartFixed() && mpDVR->IsEndFixed())
+            ss << "    int end = windowSize;\n";
+        ss << "    end = min(end, arrayLength);\n";
+        ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    int loop = arrayLength/512 + 1;\n";
+        ss << "    for (int l=0; l<loop; l++){\n";
+        ss << "    tmp = " << mpCodeGen->GetBottom() << ";\n";
+        ss << "    int loopOffset = l*512;\n";
+        ss << "    if((loopOffset + lidx + offset + 256) < end) {\n";
+        ss << "        tmp = legalize((isnan(A[loopOffset + lidx + offset])?tmp:tmp+1.0)";
+        ss << ", tmp);\n";
+        ss << "        tmp = legalize((isnan(A[loopOffset + lidx + offset+256])?tmp:tmp+1.0)";
+        ss << ", tmp);\n";
+        ss << "    } else if ((loopOffset + lidx + offset) < end)\n";
+        ss << "        tmp = legalize((isnan(A[loopOffset + lidx + offset])?tmp:tmp+1.0)";
+        ss << ", tmp);\n";
+        ss << "    shm_buf[lidx] = tmp;\n";
+        ss << "    barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    for (int i = 128; i >0; i/=2) {\n";
+        ss << "        if (lidx < i)\n";
+        ss << "            shm_buf[lidx] = ";
+        ss << "shm_buf[lidx] + shm_buf[lidx + i];\n";
+        ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    }\n";
+        ss << "        if (lidx == 0)\n";
+        ss << "            current_result =";
+        ss << "current_result + shm_buf[0];";
+        ss << ";\n";
+        ss << "        barrier(CLK_LOCAL_MEM_FENCE);\n";
+        ss << "    }\n";
+        ss << "    if (lidx == 0)\n";
+        ss << "        result[writePos] = current_result;\n";
+        ss << "}\n";
+    }
+
+}
+
+template<class Base>
+size_t ParallelReductionVectorRef<Base>::GenReductionLoopHeader(
+    std::stringstream& ss, int nResultSize, bool& needBody )
+{
+    assert(mpDVR);
+    size_t nCurWindowSize = mpDVR->GetRefRowSize();
+    std::string temp = Base::GetName() + "[gid0]";
+    ss << "tmp = ";
+    // Special case count
+    if (dynamic_cast<OpAverage*>(mpCodeGen.get()))
+    {
+        ss << mpCodeGen->Gen2(temp, "tmp") << ";\n";
+        ss << "nCount = nCount-1;\n";
+        ss << "nCount = nCount +"; /*re-assign nCount from count reduction*/
+        ss << Base::GetName() << "[gid0+" << nResultSize << "]" << ";\n";
+    }
+    else if (dynamic_cast<OpCount*>(mpCodeGen.get()))
+        ss << temp << "+ tmp";
+    else
+        ss << mpCodeGen->Gen2(temp, "tmp");
+    ss << ";\n\t";
+    needBody = false;
+    return nCurWindowSize;
+}
+
+template<class Base>
+size_t ParallelReductionVectorRef<Base>::Marshal( cl_kernel k, int argno, int w, cl_program mpProgram )
+{
+    assert(Base::mpClmem == nullptr);
+
+    openclwrapper::KernelEnv kEnv;
+    openclwrapper::setKernelEnv(&kEnv);
+    cl_int err;
+    size_t nInput = mpDVR->GetArrayLength();
+    size_t nCurWindowSize = mpDVR->GetRefRowSize();
+    // create clmem buffer
+    if (mpDVR->GetArrays()[Base::mnIndex].mpNumericArray == nullptr)
+        throw Unhandled(__FILE__, __LINE__);
+    double* pHostBuffer = const_cast<double*>(
+        mpDVR->GetArrays()[Base::mnIndex].mpNumericArray);
+    size_t szHostBuffer = nInput * sizeof(double);
+    Base::mpClmem = clCreateBuffer(kEnv.mpkContext,
+        cl_mem_flags(CL_MEM_READ_ONLY) | CL_MEM_USE_HOST_PTR,
+        szHostBuffer,
+        pHostBuffer, &err);
+    SAL_INFO("sc.opencl", "Created buffer " << Base::mpClmem << " size " << nInput << "*" << sizeof(double) << "=" << szHostBuffer << " using host buffer " << pHostBuffer);
+
+    mpClmem2 = clCreateBuffer(kEnv.mpkContext,
+        CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR,
+        sizeof(double) * w, nullptr, nullptr);
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clCreateBuffer", err, __FILE__, __LINE__);
+    SAL_INFO("sc.opencl", "Created buffer " << mpClmem2 << " size " << sizeof(double) << "*" << w << "=" << (sizeof(double)*w));
+
+    // reproduce the reduction function name
+    std::string kernelName;
+    if (!dynamic_cast<OpAverage*>(mpCodeGen.get()))
+        kernelName = Base::GetName() + "_reduction";
+    else
+        kernelName = Base::GetName() + "_sum_reduction";
+    cl_kernel redKernel = clCreateKernel(mpProgram, kernelName.c_str(), &err);
+    if (err != CL_SUCCESS)
+        throw OpenCLError("clCreateKernel", err, __FILE__, __LINE__);
+    SAL_INFO("sc.opencl", "Created kernel " << redKernel << " with name " << kernelName << " in program " << mpProgram);
+
+    // set kernel arg of reduction kernel
+    // TODO(Wei Wei): use unique name for kernel
+    cl_mem buf = Base::GetCLBuffer();
+    SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 0 << ": cl_mem: " << buf);
+    err = clSetKernelArg(redKernel, 0, sizeof(cl_mem),
+        static_cast<void*>(&buf));
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+    SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 1 << ": cl_mem: " << mpClmem2);
+    err = clSetKernelArg(redKernel, 1, sizeof(cl_mem), &mpClmem2);
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+    SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 2 << ": cl_int: " << nInput);
+    err = clSetKernelArg(redKernel, 2, sizeof(cl_int), static_cast<void*>(&nInput));
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+    SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 3 << ": cl_int: " << nCurWindowSize);
+    err = clSetKernelArg(redKernel, 3, sizeof(cl_int), static_cast<void*>(&nCurWindowSize));
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+    // set work group size and execute
+    size_t global_work_size[] = { 256, static_cast<size_t>(w) };
+    size_t const local_work_size[] = { 256, 1 };
+    SAL_INFO("sc.opencl", "Enqueing kernel " << redKernel);
+    err = clEnqueueNDRangeKernel(kEnv.mpkCmdQueue, redKernel, 2, nullptr,
+        global_work_size, local_work_size, 0, nullptr, nullptr);
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clEnqueueNDRangeKernel", err, __FILE__, __LINE__);
+    err = clFinish(kEnv.mpkCmdQueue);
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clFinish", err, __FILE__, __LINE__);
+    if (dynamic_cast<OpAverage*>(mpCodeGen.get()))
+    {
+        /*average need more reduction kernel for count computing*/
+        std::unique_ptr<double[]> pAllBuffer(new double[2 * w]);
+        double* resbuf = static_cast<double*>(clEnqueueMapBuffer(kEnv.mpkCmdQueue,
+            mpClmem2,
+            CL_TRUE, CL_MAP_READ, 0,
+            sizeof(double) * w, 0, nullptr, nullptr,
+            &err));
+        if (err != CL_SUCCESS)
+            throw OpenCLError("clEnqueueMapBuffer", err, __FILE__, __LINE__);
+
+        for (int i = 0; i < w; i++)
+            pAllBuffer[i] = resbuf[i];
+        err = clEnqueueUnmapMemObject(kEnv.mpkCmdQueue, mpClmem2, resbuf, 0, nullptr, nullptr);
+        if (err != CL_SUCCESS)
+            throw OpenCLError("clEnqueueUnmapMemObject", err, __FILE__, __LINE__);
+
+        kernelName = Base::GetName() + "_count_reduction";
+        redKernel = clCreateKernel(mpProgram, kernelName.c_str(), &err);
+        if (err != CL_SUCCESS)
+            throw OpenCLError("clCreateKernel", err, __FILE__, __LINE__);
+        SAL_INFO("sc.opencl", "Created kernel " << redKernel << " with name " << kernelName << " in program " << mpProgram);
+
+        // set kernel arg of reduction kernel
+        buf = Base::GetCLBuffer();
+        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 0 << ": cl_mem: " << buf);
+        err = clSetKernelArg(redKernel, 0, sizeof(cl_mem),
+            static_cast<void*>(&buf));
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 1 << ": cl_mem: " << mpClmem2);
+        err = clSetKernelArg(redKernel, 1, sizeof(cl_mem), &mpClmem2);
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 2 << ": cl_int: " << nInput);
+        err = clSetKernelArg(redKernel, 2, sizeof(cl_int), static_cast<void*>(&nInput));
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+        SAL_INFO("sc.opencl", "Kernel " << redKernel << " arg " << 3 << ": cl_int: " << nCurWindowSize);
+        err = clSetKernelArg(redKernel, 3, sizeof(cl_int), static_cast<void*>(&nCurWindowSize));
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+
+        // set work group size and execute
+        size_t global_work_size1[] = { 256, static_cast<size_t>(w) };
+        size_t const local_work_size1[] = { 256, 1 };
+        SAL_INFO("sc.opencl", "Enqueing kernel " << redKernel);
+        err = clEnqueueNDRangeKernel(kEnv.mpkCmdQueue, redKernel, 2, nullptr,
+            global_work_size1, local_work_size1, 0, nullptr, nullptr);
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clEnqueueNDRangeKernel", err, __FILE__, __LINE__);
+        err = clFinish(kEnv.mpkCmdQueue);
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clFinish", err, __FILE__, __LINE__);
+        resbuf = static_cast<double*>(clEnqueueMapBuffer(kEnv.mpkCmdQueue,
+            mpClmem2,
+            CL_TRUE, CL_MAP_READ, 0,
+            sizeof(double) * w, 0, nullptr, nullptr,
+            &err));
+        if (err != CL_SUCCESS)
+            throw OpenCLError("clEnqueueMapBuffer", err, __FILE__, __LINE__);
+        for (int i = 0; i < w; i++)
+            pAllBuffer[i + w] = resbuf[i];
+        err = clEnqueueUnmapMemObject(kEnv.mpkCmdQueue, mpClmem2, resbuf, 0, nullptr, nullptr);
+        // FIXME: Is it intentional to not throw an OpenCLError even if the clEnqueueUnmapMemObject() fails?
+        if (CL_SUCCESS != err)
+            SAL_WARN("sc.opencl", "clEnqueueUnmapMemObject failed: " << openclwrapper::errorString(err));
+        if (mpClmem2)
+        {
+            err = clReleaseMemObject(mpClmem2);
+            SAL_WARN_IF(err != CL_SUCCESS, "sc.opencl", "clReleaseMemObject failed: " << openclwrapper::errorString(err));
+            mpClmem2 = nullptr;
+        }
+        mpClmem2 = clCreateBuffer(kEnv.mpkContext,
+            cl_mem_flags(CL_MEM_READ_WRITE) | CL_MEM_COPY_HOST_PTR,
+            w * sizeof(double) * 2, pAllBuffer.get(), &err);
+        if (CL_SUCCESS != err)
+            throw OpenCLError("clCreateBuffer", err, __FILE__, __LINE__);
+        SAL_INFO("sc.opencl", "Created buffer " << mpClmem2 << " size " << w << "*" << sizeof(double) << "=" << (w*sizeof(double)) << " copying host buffer " << pAllBuffer.get());
+    }
+    // set kernel arg
+    SAL_INFO("sc.opencl", "Kernel " << k << " arg " << argno << ": cl_mem: " << mpClmem2);
+    err = clSetKernelArg(k, argno, sizeof(cl_mem), &mpClmem2);
+    if (CL_SUCCESS != err)
+        throw OpenCLError("clSetKernelArg", err, __FILE__, __LINE__);
+    return 1;
 }
 
 /// Helper functions that have multiple buffers
