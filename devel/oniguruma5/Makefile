# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	5.9.3
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/
DISTNAME=	onig-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A BSDL Regular Expressions library compatible with POSIX/GNU/Perl

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	oniguruma-2.*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INCLUDES/s|$$(includedir)||' ${WRKSRC}/Makefile.in

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/onig-config > ${WRKSRC}/onig-config

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/onig-config ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README ${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/sample && ${INSTALL_DATA} *.c Makefile* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
