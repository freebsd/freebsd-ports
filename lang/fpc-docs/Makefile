# New ports collection makefile for:	Free Pascal Compiler Docs
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	docs
PORTVERSION=	1.0.10
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/FreeBSD/ \
		ftp://planetmirror.com/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/FreeBSD/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/FreeBSD/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
PKGNAMEPREFIX=	fpc-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}.ELF
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Pascal compiler Adobe Acrobat(tm) documentation

DOCSDIR=	${PREFIX}/share/doc/fpc
NO_BUILD=	yes
PORTDOCS=	fcl.pdf fpdoc.pdf prog.pdf ref.pdf units.pdf user.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 470000
EXTRACT_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar --directory ${WRKSRC}
# unpack docs distribution
	@${MKDIR} ${WRKSRC}/docs
	@${TAR} zxf ${WRKSRC}/docs.tar.gz --directory ${WRKSRC}/docs

do-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_MAN} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
