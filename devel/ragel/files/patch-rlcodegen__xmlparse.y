--- rlcodegen/xmlparse.y.orig	Thu Dec 22 16:04:14 2005
+++ rlcodegen/xmlparse.y	Mon Dec 26 13:20:03 2005
@@ -175,7 +175,7 @@
 		else
 			sourceFileName = fileNameAttr->value;
 		openOutput( sourceFileName );
-	}
+	};
 
 AttributeList:
 	AttributeList Attribute {
@@ -190,7 +190,7 @@
 	XML_Word '=' XML_Literal {
 		attrKey = $1;
 		attrValue = $3;
-	}
+	};
 	
 HostOrDefList:
 	HostOrDefList HostOrDef |
@@ -204,7 +204,7 @@
 	'<' '/' TAG_host '>' {
 		if ( outputFormat == OutCCode || outputFormat == OutDCode )
 			*outStream << xmlData.data;
-	}
+	};
 
 TagHostHead:
 	'<' TAG_host AttributeList '>' {
@@ -216,14 +216,14 @@
 			if ( outputFormat == OutCCode || outputFormat == OutDCode )
 				lineDirective( *outStream, sourceFileName, line );
 		}
-	}
+	};
 
 TagRagelDef:
 	RagelDefHead
 	RagelDefItemList
 	'<' '/' TAG_ragel_def '>' {
 		cgd->generate();
-	}
+	};
 
 RagelDefHead:
 	'<' TAG_ragel_def AttributeList '>' {
@@ -303,7 +303,7 @@
 		else {
 			warning() << "unrecognized write option" << endl;
 		}
-	}
+	};
 
 
 TagAlphType:
@@ -361,7 +361,7 @@
 	'<' '/' TAG_start_state '>' {
 		unsigned long startState = strtoul( xmlData.data, 0, 10 );
 		cgd->setStartState( startState );
-	}
+	};
 
 TagEntryPoints:
 	'<' TAG_entry_points AttributeList '>'
@@ -370,7 +370,7 @@
 		Attribute *errorAttr = $3->find( "error" );
 		if ( errorAttr != 0 )
 			cgd->setForcedErrorState();
-	}
+	};
 
 EntryPointList:
 	EntryPointList TagEntry |
@@ -462,7 +462,7 @@
 			cgd->initTransList( curState, length );
 			curTrans = 0;
 		}
-	}
+	};
 
 TransList:
 	TransList TagTrans |
@@ -531,7 +531,7 @@
 	/* Nothing */ {
 		/* Start with empty list. */
 		$$ = new InlineList;
-	}
+	};
 
 InlineItem:
 	TagText |
@@ -564,7 +564,7 @@
 	'<' '/' TAG_text '>' {
 		$$ = new InlineItem( InputLoc(), InlineItem::Text );
 		$$->data = strdup(xmlData.data);
-	}
+	};
 
 TagGoto:
 	'<' TAG_goto '>'
@@ -772,7 +772,7 @@
 			cgd->initActionTableList( length );
 			curActionTable = 0;
 		}
-	}
+	};
 
 ActionTableList:
 	ActionTableList TagActionTable |
@@ -806,7 +806,7 @@
 		}
 
 		curActionTable += 1;
-	}
+	};
 
 %%
 
