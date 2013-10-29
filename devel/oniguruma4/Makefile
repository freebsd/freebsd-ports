# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	4.7.1
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/
DISTNAME=	onig-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSDL Regular Expressions library compatible with POSIX/GNU/Perl

NO_LATEST_LINK=	yes
CONFLICTS=	oniguruma-2.*
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
DOCS=		HISTORY README doc/*

PKGNAMESUFFIX=	4

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		-e 's|freebsd1|freebsd1.|' \
		${WRKSRC}/configure

post-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/onig-config > ${WRKSRC}/onig-config

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/onig-config ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.c ${WRKSRC}/sample/Makefile* \
		${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
