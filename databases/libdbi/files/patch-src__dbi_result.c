*** ./src/dbi_result.c.orig	Mon May 20 00:19:40 2013
--- ./src/dbi_result.c	Mon May 20 00:20:19 2013
***************
*** 1470,1479 ****
      switch (RESULT->field_attribs[fieldidx] & DBI_INTEGER_SIZEMASK) {
      case DBI_INTEGER_SIZE1:
        if (RESULT->field_attribs[fieldidx] & DBI_INTEGER_UNSIGNED) {
! 	snprintf(newstring, 32, "%hu", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
        }
        else {
! 	snprintf(newstring, 32, "%hd", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
        }
        break;
      case DBI_INTEGER_SIZE2:
--- 1470,1479 ----
      switch (RESULT->field_attribs[fieldidx] & DBI_INTEGER_SIZEMASK) {
      case DBI_INTEGER_SIZE1:
        if (RESULT->field_attribs[fieldidx] & DBI_INTEGER_UNSIGNED) {
! 	snprintf(newstring, 32, "%hhu", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
        }
        else {
! 	snprintf(newstring, 32, "%hhd", RESULT->rows[RESULT->currowidx]->field_values[fieldidx].d_char);
        }
        break;
      case DBI_INTEGER_SIZE2:
