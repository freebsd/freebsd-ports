# New ports collection makefile for: netscape3.language
# Date created:		17 November 1997
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netscape
PORTVERSION=	3.04
CATEGORIES=	japanese www
MASTER_SITES=	http://www.bpel.tutics.tut.ac.jp/~take/Netscape/etc/ \
		http://www.bpel.tutics.tut.ac.jp/~take/Netscape/resources/
DISTFILES=	NLS.tar.gz \
		Netscape-JPfont \
		Netscape-v301-ja_euc.ad.gz

MAINTAINER=	sada@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/netscape:${PORTSDIR}/www/netscape3 \
		${PKG_DBDIR}/ja-netscape-fonts-1.0:${PORTSDIR}/japanese/netscape-fonts

DIST_SUBDIR=	netscape3
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

# This directory is hard-coded into the netscape binary
LIBDIR=		${PREFIX}/lib/netscape

BINDIR=		${PREFIX}/bin
DOCDIR=		${PREFIX}/share/doc/ja/${DISTNAME}
NLSDIR=		${LIBDIR}/nls
RESSUB=		ja_JP.EUC
RESDIR=		${LIBDIR}/${RESSUB}

STARTFILE=	netscape.sh
STARTFILE_SRC=	${FILESDIR}/netscape.sh

do-extract:
	${MKDIR} ${WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/NLS.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/Netscape-JPfont ${WRKDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/Netscape-v301-ja_euc.ad.gz \
		| ${GUNZIP_CMD} > ${WRKDIR}/Netscape.jp.ad

do-configure:
	${SED} -e "s;@X11BASE@;${X11BASE};g" -e "s;@PREFIX@;${PREFIX};g" \
		${STARTFILE_SRC} >${WRKDIR}/${STARTFILE}

do-install:
	-${MV} ${BINDIR}/netscape ${BINDIR}/netscape.orig
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTFILE} ${BINDIR}/netscape
	${MKDIR} ${NLSDIR}/local_im_tbl
	${INSTALL_DATA} ${WRKDIR}/nls/*.*  ${LIBDIR}/nls
	${INSTALL_DATA} ${WRKDIR}/nls/C  ${LIBDIR}/nls
	${RM} -f ${LIBDIR}/nls/*.orig
	${INSTALL_DATA} ${WRKDIR}/nls/local_im_tbl/* ${LIBDIR}/nls/local_im_tbl
	${MKDIR} ${RESDIR}
.if defined(ENGLISH)
	${INSTALL_DATA} ${WRKSRC}/Netscape.ad ${RESDIR}/Netscape
	${CAT} ${WRKSRC}/Netscape-JPfont >> ${RESDIR}/Netscape
.else
	${INSTALL_DATA} ${WRKSRC}/Netscape.jp.ad ${RESDIR}/Netscape
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${FILESDIR}/setup.doc ${DOCDIR}
.endif
	@${CAT} ${DESCR}

.include <bsd.port.mk>

# This port is based on 'russian/netscape3.language(ru-netscape-3.01)'
# by asami@FreeBSD.org
