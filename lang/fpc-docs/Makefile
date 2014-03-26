# Created by: John Merryweather Cooper
# $FreeBSD$

PORTNAME=	docs
PORTVERSION=	2.6.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/${PORTVERSION}/docs/ \
		ftp://planetmirror.com/pub/fpc/dist/${PORTVERSION}/docs/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/${PORTVERSION}/docs/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/${PORTVERSION}/docs/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/${PORTVERSION}/docs/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/${PORTVERSION}/docs/
PKGNAMEPREFIX=	fpc-
DISTNAME=	${PORTNAME:S/s//}-pdf
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal compiler Adobe Acrobat(tm) documentation

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/fpdocs-${PORTVERSION}
PORTDOCS=	chart.pdf fcl.pdf fpdoc.pdf prog.pdf ref.pdf rtl.pdf user.pdf
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
