# New ports collection makefile for:    dvi2dvi
# Date created:         25 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dvi2dvi
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/ \
		ftp://ftp.math.s.chiba-u.ac.jp/tex/tex/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		web2c-7.2a.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A DVI to DVI transformer

RUN_DEPENDS=	${LOCALBASE}/share/fonts/vf-n2a:${PORTSDIR}/japanese/vftool

USE_GMAKE=	yes
MAKE_ENV+=	kpathsea_parent=../${KPATHSEA_PARENT}
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKDIR}/${KPATHSEA_PARENT}/kpathsea

KPATHSEA_PARENT=	web2c-7.2

.include <bsd.port.pre.mk>

post-extract:
	@( cd ${WRKSRC} ; ${MV} lib-dist lib )
	@${CP} ${FILESDIR}/fontdesc ${WRKSRC}/lib

pre-build:
	@( cd ${WRKDIR}/${KPATHSEA_PARENT}/kpathsea ; ${GMAKE} )

pre-install:
.for i in config configk fonts/p2n fontsk/p2n
	@${CP} ${WRKSRC}/lib/$i ${WRKSRC}/lib/$i.orig
	@${SED} -e 's,@PREFIX@,${PREFIX},g' \
	  ${WRKSRC}/lib/$i.orig > ${WRKSRC}/lib/$i
.endfor

post-install:
	@${RM} ${WRKSRC}/lib/*.orig \
	  ${WRKSRC}/lib/fonts/*.orig ${WRKSRC}/lib/fontsk/*.orig
	@( cd ${WRKSRC} ; ${MAKE} PREFIX=${PREFIX} install-lib )
	@${MKDIR} -m 777 ${PREFIX}/share/fonts/vf-rot
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dvi2dvi
	@${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/dvi2dvi
.endif

.include <bsd.port.post.mk>
