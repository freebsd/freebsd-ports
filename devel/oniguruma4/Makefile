# New ports collection makefile for:	oniguruma4
# Date created:		31 January 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	oniguruma
PORTVERSION=	4.5.0
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/
DISTNAME=	onig-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A BSDL Regular Expressions library compatible with POSIX/GNU/Perl

CONFLICTS=	oniguruma-2.*
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
DOCS=		HISTORY README doc/*

post-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/onig-config > ${WRKSRC}/onig-config

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/onig-config ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.c ${WRKSRC}/sample/Makefile* \
		${EXAMPLESDIR}/
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
