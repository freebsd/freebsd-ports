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
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b-/}
DIST_SUBDIR=	wxg

MAINTAINER=	knu@FreeBSD.org

# We need Canna libraries to use WXG anyway, and some Canna utilities
# are useful for WXG too.
RUN_DEPENDS=	cannakill:${PORTSDIR}/japanese/Canna

RESTRICTED=	"You must not copy or redistribute the distfile or the package."
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

BINS=		wxgdic wxgdmp wxgdset
SBINS=		wxgserver

.include <bsd.port.pre.mk>

.if !exists(${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='You must visit http://www.ekotoba.com/download/dldata.asp?kind=1&data=1 and agree with the licence terms to fetch "${DISTFILE}".  After the download is done, place it in ${_DISTDIR} and run make again.'
.endif

do-fetch:
#	should not reach here

post-extract:
	cd ${WRKSRC} && \
	for t in wxg.freebsd.tar.gz wxgdics.tar.gz wxghtml.tar.gz; \
	do ${TAR} zxf $${t}; done

do-build:
	${SED} 's,!!PREFIX!!,${PREFIX},g' ${FILESDIR}/wxg.sh > ${WRKSRC}/wxg.sh
	${WRKSRC}/wxg/wxgdset ${WRKSRC}/dic/wxg.gds -U=2 -L=0 wxgu.gdj wxg.gdj wxgtx.gdj seimei.gdj chimei.gdj yubin.gdj kao.gdj english.gdj
	${WRKSRC}/wxg/wxgdset ${WRKSRC}/dic/wxgsei.gds -U=2 -L=0 wxgu.gdj wxg.gdj seimei.gdj chimei.gdj yubin.gdj tel.gdj
	${WRKSRC}/wxg/wxgdset ${WRKSRC}/dic/wxgseiu.gds -C=${PREFIX}/wxg/dic/ -U=2 -L=0 wxgu.gdj wxg.gdj -p3 seimei.gdj -p3 chimei.gdj -p3 yubin.gdj -p3 tel.gdj -p3
	${WRKSRC}/wxg/wxgdset ${WRKSRC}/dic/wxgu.gds -C=${PREFIX}/lib/wxg/dic/ -U=2 -L=0 wxgu.gdj wxg.gdj -p3 wxgtx.gdj -p3 seimei.gdj -p3 chimei.gdj -p3 yubin.gdj -p3 kao.gdj -p3 english.gdj -p3

do-install:
	cd ${WRKSRC}/wxg && ${INSTALL_PROGRAM} ${BINS} ${PREFIX}/bin/
	cd ${WRKSRC}/wxg && ${INSTALL_PROGRAM} ${SBINS} ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/lib/wxg/dic ${PREFIX}/lib/wxg/roma
	${INSTALL_DATA} ${WRKSRC}/wxg/wxgrc ${WRKSRC}/dic/wxg.gct ${PREFIX}/lib/wxg
	${INSTALL_DATA} ${WRKSRC}/dic/*.txt ${WRKSRC}/dic/*.gd? ${PREFIX}/lib/wxg/dic
	${INSTALL_DATA} ${WRKSRC}/dic/*.grt ${PREFIX}/lib/wxg/roma
	${INSTALL_SCRIPT} ${WRKSRC}/wxg.sh ${PREFIX}/etc/rc.d/wxg.sh.sample
	[ X${PREFIX} = X"/usr/local" ] || ${LN} -s ${PREFIX}/lib/wxg /usr/local/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wxg
	${CP} -R ${WRKSRC}/README ${WRKSRC}/html ${PREFIX}/share/doc/wxg/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
