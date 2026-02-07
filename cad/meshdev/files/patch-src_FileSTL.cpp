--- /dev/null	2012-02-06 16:11:28.000000000 +0100
+++ src/FileSTL.cpp	2012-02-06 16:12:28.000000000 +0100
@@ -0,0 +1,150 @@
+/*-
+Copyright (C) 2012 Pietro Cerutti <gahr@gahr.ch>
+
+Redistribution and use in source and binary forms, with or without
+modification, are permitted provided that the following conditions
+are met:
+1. Redistributions of source code must retain the above copyright
+   notice, this list of conditions and the following disclaimer.
+2. Redistributions in binary form must reproduce the above copyright
+   notice, this list of conditions and the following disclaimer in the
+   documentation and/or other materials provided with the distribution.
+
+THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
+ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
+FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+SUCH DAMAGE.
+*/
+
+#include "FileSTL.h"
+#include <fstream>
+#include <iostream>
+#include <cstdio>
+
+//--
+//
+// ReadSTL
+//
+// --
+// Read a binary or ASCII STL file
+bool ReadSTL( Mesh& mesh, const std::string& file_name )
+{
+   std::ifstream file;     // File to read
+   char head[7];           // File header
+   float coords[3];        // Store a coordinate
+   unsigned int nof_faces; // Number of faces (always multiple of 3)
+   unsigned int i, j;
+
+   /* Open file */
+   file.open(file_name.c_str(), std::ios::binary);
+
+   /* Test if file is open */
+   if (file.is_open() == false) {
+      return (false);
+   }
+
+   /* Read header */
+   file.read(head, 6);
+   head[6] = '\0';
+
+   /* Reposition at beginning of file */
+   file.seekg(0, std::ios_base::beg);
+
+   /* Initialize the mesh */
+   mesh.ClearAll();
+
+   if (strcmp(head, "solid ") == 0) {
+      /*
+       * Read ASCII STL
+       */
+
+      nof_faces= 0;
+
+      std::string line;
+
+      /* ignore first line */
+      std::getline(file, line);
+
+      /*
+       * Read the file line by line
+       */
+      while (std::getline(file, line)) {
+
+         /* skip description lines */
+
+         if (line.compare("outer loop") == 0) {
+            continue;
+         }
+         if (line.compare("endloop") == 0) {
+            continue;
+         }
+         if (line.compare("end facet") == 0) {
+            continue;
+         }
+         if (line.compare(0, 7, "endsolid")) {
+            break;
+         }
+
+         /* facet normal */
+         if (line.compare(0, 12, "facet normal") == 0) {
+            sscanf(line.c_str(), "facet normal %e %e %e", &coords[0], &coords[1], &coords[2]);
+            mesh.AddVertexNormal(Vector3d(coords[0], coords[1], coords[2]));
+         }
+
+         /* vertex */ 
+         if (line.compare(0, 6, "vertex") == 0) {
+            sscanf(line.c_str(), "vertex %e %e %e", &coords[0], &coords[1], &coords[2]);
+            mesh.AddVertex(Vector3d(coords[0], coords[1], coords[2]));
+
+            if (++nof_faces % 3) {
+               mesh.AddFace(Vector3i((int)nof_faces-1, (int)nof_faces-2, (int)nof_faces-3));
+            }
+         }
+      }
+
+
+   } else {
+      /*
+       * Read binary STL
+       */
+
+      /* skip first 80 bytes (header) */
+      file.seekg(80, std::ios_base::beg);
+
+      /* read number of triangles */
+      file.read((char *)&nof_faces, 4);
+
+      /*
+       * read the file triangle by triangle
+       */
+      for (i=0; i<nof_faces; i++) {
+
+         /* facet normal */
+         file.read((char *)&coords, 12);
+         mesh.AddVertexNormal(Vector3d(coords[0], coords[1], coords[2]));
+
+         /* vertices */
+         for (j=0; j<3; j++) {
+            file.read((char *)&coords, 12);
+            mesh.AddVertex(Vector3d(coords[0], coords[1], coords[2]));
+         }
+         mesh.AddFace(Vector3i((int)(i*3), (int)(i*3)+1, (int)(i*3)+2));
+
+         /* skip 2 bytes */
+         file.seekg(2, std::ios_base::cur);
+      }
+
+   }
+
+	// Close file
+	file.close();
+
+   return (true);
+}
