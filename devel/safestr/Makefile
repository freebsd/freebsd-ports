# Ports collection makefile for:        safestr
# Date created:                         28 Aug 2003
# Whom:                                 Robert Schlotterbeck <robert@rs.tarrant.tx.us>
#
# $FreeBSD$
#

PORTNAME=	safestr
PORTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	http://www.zork.org/software/

MAINTAINER=	robert@rs.tarrant.tx.us
COMMENT=	A string handling library for C

LIB_DEPENDS=	xxl.1:${PORTSDIR}/devel/xxl:install

CONFIGURE_ARGS+=	--with-xxl=${LOCALBASE}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		safestr.3 safestr_alloc.3 safestr_charat.3 safestr_clone.3 \
		safestr_compare.3 safestr_concatenate.3 safestr_convertarray.3 \
		safestr_create.3 safestr_delete.3 safestr_duplicate.3 \
		safestr_equal.3 safestr_free.3 safestr_insert.3 safestr_join.3 \
		safestr_length.3 safestr_makereadonly.3 safestr_memzero.3 \
		safestr_printf.3 safestr_reference.3 safestr_replace.3 \
		safestr_search.3 safestr_setmemfns.3 safestr_slice.3 safestr_strdup.3 \
		safestr_truncate.3 safestr_trust.3

MLINKS=		safestr_charat.3 safestr_setcharat.3 \
		safestr_compare.3 safestr_ncompare.3 \
		safestr_create.3 SAFESTR_TEMP.3 \
		safestr_duplicate.3 safestr_copy.3 \
		safestr_free.3 safestr_release.3 \
		safestr_makereadonly.3 safestr_isreadonly.3 \
		safestr_printf.3 safestr_fprintf.3 \
		safestr_printf.3 safestr_sprintf.3 \
		safestr_search.3 safestr_find.3 \
		safestr_trust.3 safestr_untrust.3 \
		safestr_charat.3 safestr_setcharat_nonfatal.3 \
		safestr_concatenate.3 safestr_append.3 \
		safestr_create.3 SAFESTR_TEMP_TRUSTED.3 \
		safestr_duplicate.3 safestr_ncopy.3 \
		safestr_makereadonly.3 safestr_makewritable.3 \
		safestr_printf.3 safestr_vprintf.3 \
		safestr_printf.3 safestr_vfprintf.3 \
		safestr_printf.3 safestr_vsprintf.3 \
		safestr_search.3 safestr_nfind.3 \
		safestr_trust.3 safestr_istrusted.3 \
		safestr_charat.3 safestr_charat_nonfatal.3

.include <bsd.port.mk>
