--- src/core/renderer/StelQGLArrayVertexBufferBackend.cpp.orig	2013-04-21 15:22:59.000000000 +0800
+++ src/core/renderer/StelQGLArrayVertexBufferBackend.cpp	2013-10-19 19:47:23.000000000 +0800
@@ -42,7 +42,7 @@ StelQGLArrayVertexBufferBackend(const Pr
 		const StelVertexAttribute& attribute(this->attributes.attributes[attrib]);
 
 		attributeBuffers[attribute.interpretation] =
-			std::malloc(vertexCapacity * attributeSize(attribute.type));
+			::malloc(vertexCapacity * attributeSize(attribute.type));
 	}
 }
 
@@ -50,11 +50,11 @@ StelQGLArrayVertexBufferBackend::~StelQG
 {
 	for(int buffer = 0; buffer < AttributeInterpretation_MAX; ++buffer)
 	{
-		if(NULL != attributeBuffers[buffer]){std::free(attributeBuffers[buffer]);}
+		if(NULL != attributeBuffers[buffer]){::free(attributeBuffers[buffer]);}
 	}
 	if(NULL != projectedPositions)
 	{
-		std::free(projectedPositions);
+		::free(projectedPositions);
 	}
 }
 
@@ -71,7 +71,7 @@ void StelQGLArrayVertexBufferBackend::ad
 		{
 			const StelVertexAttribute& attribute(attributes.attributes[attrib]);
 			attributeBuffers[attribute.interpretation] = 
-				std::realloc(attributeBuffers[attribute.interpretation], 
+				::realloc(attributeBuffers[attribute.interpretation], 
 				             vertexCapacity * attributeSize(attribute.type));
 		}
 	}
@@ -167,12 +167,12 @@ void StelQGLArrayVertexBufferBackend::
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
 
