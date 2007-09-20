# ex:ts=8
# Ports collection makefile for:  pcc
# Date created:			  Mon Sept 17, 2007
# Whom:				  David O'Brien (obrien@NUXI.org)
#
# $FreeBSD$
#

PORTNAME=	pcc
DATESPEC=	070920
PORTVERSION=	0.9.8.${DATESPEC}
PORTREVISION?=	0
CATEGORIES=	lang
MASTER_SITES=	ftp://226.net120.skekraft.net/pcc/
DISTNAME=	pcc-${DATESPEC}
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	S.C.Johnson's Portable C Compiler brought into the C99 world.

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}-${DATESPEC}
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	YACC=${YACC}
CONFIGURE_TARGET= --build=${ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

PLIST_FILES=	bin/pcc libexec/ccom libexec/cpp

pre-configure:
	${MKDIR} ${WRKSRC}/os/freebsd
	${LN} -sf ${FILESDIR}/*.h ${WRKSRC}/os/freebsd

.include <bsd.port.mk>
