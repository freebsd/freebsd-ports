libs/shadervm/dsoshadeops.cpp:150:44: error: cast from pointer to smaller type 'char' loses information
                            while( ( pShadeOp->m_opspec )[0] != (char) NULL )
                                                                ^~~~~~~~~~~

--- libs/shadervm/dsoshadeops.cpp.orig	2012-08-24 12:26:50 UTC
+++ libs/shadervm/dsoshadeops.cpp
@@ -147,7 +147,7 @@ CqDSORepository::getShadeOpMethods(CqString* pShadeOpN
 		    {
 			    //We have an appropriate named shadeop table
 			    SqShadeOp *pShadeOp = (SqShadeOp*) pTableSymbol;
-			    while( ( pShadeOp->m_opspec )[0] != (char) NULL )
+			    while( ( pShadeOp->m_opspec )[0] != '\0' )
 			    {
 				    SqDSOExternalCall *pDSOCall = NULL;
 				    pDSOCall = parseShadeOpTableEntry( handle, pShadeOp );
