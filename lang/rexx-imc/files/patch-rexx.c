--- rexx.c.upper	Tue Feb 26 12:29:20 2002
+++ rexx.c	Thu Jun 20 16:33:44 2002
@@ -1366,6 +1366,39 @@
                if(write(rxstacksock,pull,8)<8||
                   (len>0&&write(rxstacksock,exp,len)<len)) die(Esys);
                break;
+            case UPPER: /* go along the list, find each variable and uppercase it */
+               while (*lineptr) {
+                  tmpchr = *lineptr==' ';
+                  getvarname(lineptr,&tmpchr,varname,&varlen,maxvarname);
+                  lineptr+=tmpchr;
+                  if(!varname[0])die(Enosymbol);
+                  exp=varget(varname,varlen,&len);
+                  if (exp) { /* variable has a value - uppercase in place */
+                     int j;
+                     for(j=0; j<len; j++)
+                        exp[j]=uc(exp[j]);
+                  } else { /* novalue */
+                     /* make a copy of the variable's value, i.e., its name */
+                     len=varlen;
+                     mtest(workptr, worklen, len+2, len+2-worklen);
+                     memcpy(workptr, varname, len);
+                     /* undo the special rules for compound symbols */
+                     if (workptr[0]&128 && !memchr(workptr, '.', len))
+                        workptr[len++]='.';
+                     workptr[0] &= 127;
+                     /* trap a novalue error */
+                     if(sgstack[interplev].bits&(1<<Inovalue)) {
+                        workptr[len]=0;
+                        errordata=workptr;
+                        die(Enovalue);
+                     }
+                     /* if trap wasn't caught, set the variable */
+                     /* (it might not be in upper case if it was a compound) */
+                     for (i=0; i<len; i++) workptr[i]=uc(workptr[i]);
+                     varset(varname, varlen, workptr, len);
+                  }
+               }
+               break;
             /* Anything else is a syntax error.  However, under normal
             circumstances we should never get here. */
             default:die(Esyntax);
