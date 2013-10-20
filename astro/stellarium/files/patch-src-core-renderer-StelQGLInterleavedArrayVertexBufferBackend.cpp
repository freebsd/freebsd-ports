--- src/core/renderer/StelQGLInterleavedArrayVertexBufferBackend.cpp.orig	2013-08-04 14:20:27.000000000 +0800
+++ src/core/renderer/StelQGLInterleavedArrayVertexBufferBackend.cpp	2013-10-19 19:47:06.000000000 +0800
@@ -42,15 +42,15 @@ StelQGLInterleavedArrayVertexBufferBacke
 	}
 	// Align to VERTEX_ALIGN
 	vertexStride = (vertexBytes + VERTEX_ALIGN - 1) & ~(VERTEX_ALIGN - 1);
-	vertices = static_cast<char*>(std::malloc(vertexCapacity * vertexStride));
+	vertices = static_cast<char*>(::malloc(vertexCapacity * vertexStride));
 }
 
 StelQGLInterleavedArrayVertexBufferBackend::~StelQGLInterleavedArrayVertexBufferBackend()
 {
-	std::free(vertices);
+	::free(vertices);
 	if(NULL != projectedPositions)
 	{
-		std::free(projectedPositions);
+		::free(projectedPositions);
 	}
 }
 
@@ -63,7 +63,7 @@ void StelQGLInterleavedArrayVertexBuffer
 	if(Q_UNLIKELY(vertexCount == vertexCapacity))
 	{
 		vertexCapacity *= 2;
-		vertices = static_cast<char*>(std::realloc(vertices, vertexCapacity * vertexStride));
+		vertices = static_cast<char*>(::realloc(vertices, vertexCapacity * vertexStride));
 	}
 
 	std::memcpy(vertices + vertexCount * vertexStride, vertexInPtr, vertexBytes);
@@ -122,12 +122,12 @@ void StelQGLInterleavedArrayVertexBuffer
 	if(Q_UNLIKELY(NULL == projectedPositions))
 	{
 		projectedPositions =
-			static_cast<Vec3f*>(std::malloc(minProjectedSize * sizeof(Vec3f)));
+			static_cast<Vec3f*>(::malloc(minProjectedSize * sizeof(Vec3f)));
 	}
 	else if(projectedPositionsCapacity < minProjectedSize)
 	{
 		projectedPositions =
-			static_cast<Vec3f*>(std::realloc(projectedPositions, minProjectedSize * sizeof(Vec3f)));
+			static_cast<Vec3f*>(::realloc(projectedPositions, minProjectedSize * sizeof(Vec3f)));
 		projectedPositionsCapacity = minProjectedSize;
 	}
 
