# New ports collection makefile for:	bookview
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	bookview
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/net/ndtp/bookview/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NDTP client written in Tcl/Tk

USE_TK_WRAPPER=		yes

do-build:
.for i in bookview/bookview doc/bookview.html
	cd ${WRKSRC} && ${SED} -e \
		's|@WISH@|${WISH}|g ; \
		 s|@VERSION@|${PORTVERSION}|g ; \
		 s|@sysconfdir@|${PREFIX}/etc|g ; \
		 s|@pkgdatadir@|${DATADIR}|g' < ${i}.in > ${i}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bookview/bookview ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bitmap/*.gif ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bitmap/*.xbm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bookview/*.tcl ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bookview/*.mo ${DATADIR}
	@${MKDIR} ${DATADIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.css ${DATADIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DATADIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DATADIR}/doc

.include <bsd.port.mk>
