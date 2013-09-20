# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
PORTVERSION=	2.5.8
CATEGORIES=	devel textproc
MASTER_SITES=	http://www.geocities.jp/kosako3/oniguruma/archive/:onig \
		http://www.SpringDaemons.com/stas/:ruby
DISTFILES=	onigd${PORTVERSION:S/./_/g}${EXTRACT_SUFX}:onig \
		ruby187p248-oniguruma.patch:ruby
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	onigd${PORTVERSION:S/./_/g}${EXTRACT_SUFX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A BSDL Regular Expressions library compatible with POSIX/GNU/Perl

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_LATEST_LINK=	yes
CONFLICTS_INSTALL=	oniguruma-4.*

GNU_CONFIGURE=	yes
DOCS=		HISTORY README doc/*

NO_STAGE=	yes
post-patch:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ruby187p248-oniguruma.patch \
		${WRKSRC}/ruby187.patch

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
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
