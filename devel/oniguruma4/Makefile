# New ports collection makefile for:	Oniguruma
# Date created:		31 January 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	oniguruma
PORTVERSION=	2.5.7
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/
DISTNAME=	onigd${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A BSDL Regular Expressions library compatible with POSIX/GNU/Perl

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
#INSTALLS_SHLIB=	yes

DOCS=		HISTORY README doc/*

post-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/onig-config > ${WRKSRC}/onig-config

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/onig-config ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}/
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
