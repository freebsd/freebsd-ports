# New ports collection makefile for:    dvi2dvi
# Version required:     1.0
# Date created:         25 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $Id$
#

DISTNAME=	dvi2dvi-1.0
PKGNAME=	ja-dvi2dvi-1.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

RUN_DEPENDS=	${PREFIX}/share/fonts/vf-n2a:${PORTSDIR}/japanese/vftool

post-extract:
	@( cd ${WRKSRC} ; ${MAKE} newlib )
	@${CP} ${FILESDIR}/fontdesc ${WRKSRC}/lib

post-patch:
.for i in config p2n
	@${CP} ${WRKSRC}/lib/$i ${WRKSRC}/lib/$i.orig
	@${SED} -e 's,@PREFIX@,${PREFIX},g' \
	  ${WRKSRC}/lib/$i.orig > ${WRKSRC}/lib/$i
.endfor

post-install:
	@${RM} ${WRKSRC}/lib/*.orig
	@( cd ${WRKSRC} ; ${MAKE} PREFIX=${PREFIX} install-lib )
	@${MKDIR} -m 777 ${PREFIX}/share/fonts/vf-rot
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dvi2dvi
	@${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/dvi2dvi
.endif

.include <bsd.port.mk>
