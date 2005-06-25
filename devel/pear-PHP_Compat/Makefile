# Ports collection makefile for:  pear-PHP_Compat
# Date created:			  22 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_Compat
PORTVERSION=	1.4.1
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Provides missing functionality for older versions of PHP

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	PHP
FILES=		Compat.php Compat/Components.php \
		Compat/Constant/DIRECTORY_SEPARATOR.php \
		Compat/Constant/E_STRICT.php Compat/Constant/PATH_SEPARATOR.php \
		Compat/Constant/STD.php Compat/Constant/FILE.php \
		Compat/Constant/PHP_EOL.php Compat/Constant/UPLOAD_ERR.php \
		Compat/Constant/T.php Compat/Function/array_change_key_case.php \
		Compat/Function/array_chunk.php \
		Compat/Function/array_combine.php \
		Compat/Function/array_diff_assoc.php \
		Compat/Function/array_diff_key.php \
		Compat/Function/array_diff_uassoc.php \
		Compat/Function/array_diff_ukey.php \
		Compat/Function/array_intersect_assoc.php \
		Compat/Function/array_intersect_key.php \
		Compat/Function/array_intersect_uassoc.php \
		Compat/Function/array_intersect_ukey.php \
		Compat/Function/array_key_exists.php \
		Compat/Function/array_search.php \
		Compat/Function/array_udiff.php \
		Compat/Function/array_udiff_assoc.php \
		Compat/Function/array_udiff_uassoc.php \
		Compat/Function/array_uintersect.php \
		Compat/Function/array_uintersect_assoc.php \
		Compat/Function/array_uintersect_uassoc.php \
		Compat/Function/array_walk_recursive.php \
		Compat/Function/call_user_func_array.php \
		Compat/Function/clone.php Compat/Function/constant.php \
		Compat/Function/convert_uuencode.php \
		Compat/Function/convert_uudecode.php \
		Compat/Function/debug_print_backtrace.php \
		Compat/Function/file_get_contents.php \
		Compat/Function/file_put_contents.php \
		Compat/Function/floatval.php Compat/Function/fprintf.php \
		Compat/Function/fputcsv.php Compat/Function/get_headers.php \
		Compat/Function/get_include_path.php \
		Compat/Function/html_entity_decode.php \
		Compat/Function/htmlspecialchars_decode.php \
		Compat/Function/http_build_query.php \
		Compat/Function/ibase_timefmt.php \
		Compat/Function/image_type_to_mime_type.php \
		Compat/Function/ini_get_all.php Compat/Function/is_a.php \
		Compat/Function/md5_file.php Compat/Function/mhash.php \
		Compat/Function/ob_clean.php Compat/Function/ob_flush.php \
		Compat/Function/ob_get_clean.php \
		Compat/Function/ob_get_flush.php \
		Compat/Function/php_strip_whitespace.php \
		Compat/Function/pg_affected_rows.php \
		Compat/Function/pg_escape_bytea.php \
		Compat/Function/pg_unescape_bytea.php \
		Compat/Function/restore_include_path.php \
		Compat/Function/scandir.php \
		Compat/Function/set_include_path.php \
		Compat/Function/str_ireplace.php \
		Compat/Function/str_rot13.php Compat/Function/str_split.php \
		Compat/Function/str_shuffle.php \
		Compat/Function/str_word_count.php \
		Compat/Function/stripos.php Compat/Function/strpbrk.php \
		Compat/Function/strripos.php \
		Compat/Function/substr_compare.php \
		Compat/Function/var_export.php \
		Compat/Function/version_compare.php \
		Compat/Function/vprintf.php Compat/Function/vsprintf.php
TESTS=		loadconstant.phpt loadfunction.phpt loadversion.phpt \
		constant/directory_separator.phpt constant/e_strict.phpt \
		constant/file.phpt constant/path_separator.phpt \
		constant/std.phpt constant/php_eol.phpt \
		constant/upload_err.phpt constant/t.phpt \
		function/array_change_key_case.phpt \
		function/array_chunk.phpt function/array_combine.phpt \
		function/array_diff_assoc.phpt \
		function/array_diff_uassoc.phpt \
		function/array_diff_key.phpt \
		function/array_diff_ukey.phpt \
		function/array_intersect_assoc.phpt \
		function/array_intersect_key.phpt \
		function/array_intersect_uassoc.phpt \
		function/array_intersect_ukey.phpt \
		function/array_key_exists.phpt \
		function/array_search.phpt function/array_udiff.phpt \
		function/array_udiff_assoc.phpt \
		function/array_udiff_uassoc.phpt \
		function/array_uintersect.phpt \
		function/array_uintersect_assoc.phpt \
		function/array_uintersect_uassoc.phpt \
		function/array_walk_recursive.phpt \
		function/call_user_func_array.phpt function/clone.phpt \
		function/constant.phpt function/convert_uuencode.phpt \
		function/convert_uudecode.phpt \
		function/debug_print_backtrace.phpt \
		function/file_get_contents.phpt \
		function/file_put_contents.phpt function/floatval.phpt \
		function/fprintf.phpt function/fputcsv.phpt \
		function/get_headers.phpt function/get_include_path.phpt \
		function/html_entity_decode.phpt \
		function/htmlspecialchars_decode.phpt \
		function/http_build_query.phpt \
		function/ibase_timefmt.phpt \
		function/image_type_to_mime_type.phpt \
		function/ini_get_all.phpt function/is_a.phpt \
		function/md5_file.phpt function/mhash.phpt \
		function/ob_clean.phpt function/ob_flush.phpt \
		function/ob_get_clean.phpt function/ob_get_flush.phpt \
		function/php_strip_whitespace.phpt \
		function/pg_affected_rows.phpt \
		function/pg_escape_bytea.phpt \
		function/pg_unescape_bytea.phpt \
		function/restore_include_path.phpt function/scandir.phpt \
		function/set_include_path.phpt function/str_ireplace.phpt \
		function/str_rot13.phpt function/str_split.phpt \
		function/str_shuffle.phpt function/str_word_count.phpt \
		function/stripos.phpt function/strpbrk.phpt \
		function/strripos.phpt function/substr_compare.phpt \
		function/var_export.phpt function/version_compare.phpt \
		function/vprintf.phpt function/vsprintf.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
