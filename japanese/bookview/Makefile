# Created by: Motoyuki Kasahara <m-kasahr@sra.co.jp>
# $FreeBSD$

PORTNAME=	bookview
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/net/ndtp/bookview/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NDTP client written in Tcl/Tk

USES=		tk:wrapper

do-build:
.for i in bookview/bookview doc/bookview.html
	cd ${WRKSRC} && ${SED} -e \
		's|@WISH@|${WISH}|g ; \
		 s|@VERSION@|${PORTVERSION}|g ; \
		 s|@sysconfdir@|${PREFIX}/etc|g ; \
		 s|@pkgdatadir@|${DATADIR}|g' < ${i}.in > ${i}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bookview/bookview ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bitmap/*.gif ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bitmap/*.xbm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bookview/*.tcl ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bookview/*.mo ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.css ${STAGEDIR}${DATADIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DATADIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${STAGEDIR}${DATADIR}/doc

.include <bsd.port.mk>
