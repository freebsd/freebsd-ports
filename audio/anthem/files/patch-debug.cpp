*** ../anthem-0.0.17.old/anthem/misc/debug.cpp	Sun Jul 28 11:13:06 2002
--- anthem/misc/debug.cpp	Wed Nov 12 21:47:26 2003
***************
*** 24,36 ****
  {
      for (unsigned int n = 0; n < depth; n++) std::cerr << " ";
      depth++;
!     std::cerr << "> " << m_fn_name << endl;
  }
  
  dbg::trace_function::~trace_function()
  {
      depth--;
      for (unsigned int n = 0; n < depth; n++) std::cerr << " ";
!     std::cerr << "< " << m_fn_name << endl;
  }
  
--- 24,36 ----
  {
      for (unsigned int n = 0; n < depth; n++) std::cerr << " ";
      depth++;
!     std::cerr << "> " << m_fn_name << std::endl;
  }
  
  dbg::trace_function::~trace_function()
  {
      depth--;
      for (unsigned int n = 0; n < depth; n++) std::cerr << " ";
!     std::cerr << "< " << m_fn_name << std::endl;
  }
  
