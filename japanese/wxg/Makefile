# New ports collection makefile for:	WXG for FreeBSD
# Date created:		5 Dec 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	wxg
PORTVERSION=	1.0.b1
CATEGORIES=	japanese
MASTER_SITES=	http://web.infoweb.ne.jp/aisoft/ekotoba/
DISTNAME=	ja-${PORTNAME}-${PORTVERSION:S/.b/b-/}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	wxg

MAINTAINER=	knu@FreeBSD.org

# We need Canna libraries to use WXG anyway, and some Canna utilities
# are useful for WXG too.
RUN_DEPENDS=	cannakill:${PORTSDIR}/japanese/Canna

RESTRICTED=	"You must not copy or redistribute the distfile or the package."
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

NO_WRKSUBDIR=	YES

BINS=		wxgdic wxgdmp wxgdset
SBINS=		wxgserver

.include <bsd.port.pre.mk>

.if !exists(${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='You must visit http://www.ekotoba.com/download/dldata.asp?kind=1&data=3 and agree with the licence terms to fetch "${DISTFILE}".  After the download is donw, place it in ${_DISTDIR} and run make again.'
.endif

do-fetch:
#	should not reach here

post-extract:
	${MV} ${WRKSRC}/lib/wxg/doc ${WRKSRC}
	${RM} -rf ${WRKSRC}/lib/wxg/sample

do-build:
	${SED} 's,!!PREFIX!!,${PREFIX},g' ${FILESDIR}/wxg.sh > ${WRKSRC}/wxg.sh

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} ${BINS} ${PREFIX}/bin/
	cd ${WRKSRC}/sbin && ${INSTALL_PROGRAM} ${SBINS} ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/lib/wxg
	${INSTALL_SCRIPT} ${WRKSRC}/wxg.sh ${PREFIX}/etc/rc.d/wxg.sh.sample
	${CP} -R ${WRKSRC}/lib/wxg/* ${PREFIX}/lib/wxg/
	[ X${PREFIX} = X"/usr/local" ] || ${LN} -s ${PREFIX}/lib/wxg /usr/local/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wxg
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/wxg/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
