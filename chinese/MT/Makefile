# New ports collection makefile for:	MT
# Date created:		7 Oct 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sincia.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	MT
PORTVERSION=	2.661
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	http://mtbook.net/download/
DISTFILES=	MT-${PORTVERSION}-full-lib.new.tar.gz mt.diff mt.no-htmlarea.diff
EXTRACT_ONLY=	MT-${PORTVERSION}-full-lib.new.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based personal publishing system like weblogs

RUN_DEPENDS=	${LOCALBASE}/${CGIDIR}/mt.cgi:${PORTSDIR}/www/MT

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DATADIR=	www/data/mt
CGIDIR=		www/cgi-bin/mt
PLIST_SUB+=	DATADIR=${DATADIR} CGIDIR=${CGIDIR}
PATCH_MT_ARGS=	-d ${PREFIX}/${CGIDIR} --forward --quiet -E -p1
USE_REINPLACE=	yes
PKGDEINSTALL=	${PKGINSTALL}

.if defined(WITH_HTMLAREA)
MT_DIFF=	mt.diff
.else
MT_DIFF=	mt.no-htmlarea.diff
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/${DATADIR} ${WRKDIR}/${CGIDIR}
	@${MV} ${WRKDIR}/MT-${PORTVERSION}-full-lib/lib ${WRKDIR}/${CGIDIR}
	@${MV} ${WRKDIR}/MT-${PORTVERSION}-full-lib/extlib ${WRKDIR}/${CGIDIR}
	@${MV} ${WRKDIR}/MT-${PORTVERSION}-full-lib/*cgi ${WRKDIR}/${CGIDIR}
	@${MV} ${WRKDIR}/MT-${PORTVERSION}-full-lib/mt-rebuild.pl ${WRKDIR}/MT-${PORTVERSION}-full-lib/plugins/mt-rebuild.pl
	@${MV} ${WRKDIR}/MT-${PORTVERSION}-full-lib/* ${WRKDIR}/${DATADIR}
	@${RMDIR} ${WRKDIR}/MT-${PORTVERSION}-full-lib
	@${CHMOD} ${BINMODE} ${WRKDIR}/${CGIDIR}/*cgi

do-install:
	@${REINPLACE_CMD} -e 's/# PublishCharset Shift_JIS/PublishCharset UTF-8/g' \
		${LOCALBASE}/${CGIDIR}/mt.cgi
	@cd ${WRKDIR} && ${CP} -R www ${PREFIX}
	@${ECHO} "===>   Patching www/MT for ${PKGNAME}"
	@${CAT} ${DISTDIR}/${MT_DIFF} | \
		${SED} -e 's#$$MT_DIR, .schemas.#"${PREFIX}/${DATADIR}/schemas"#' > \
		${PREFIX}/${DATADIR}/mt.diff
	@${FIND} ${PREFIX}/${CGIDIR} \( -name "*.orig" -o -name "*.bak" -o -name "*.rej" \) -delete
	@${CHOWN} -R www:www ${PREFIX}/${CGIDIR} ${PREFIX}/${DATADIR}

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
