# ex:ts=8
# Ports collection makefile for:  pcc
# Date created:			  Mon Sept 17, 2007
# Whom:				  David O'Brien (obrien@NUXI.org)
#
# $FreeBSD$
#

PORTNAME=	pcc
DATESPEC=	080213
PORTVERSION=	0.9.9.${DATESPEC}
PORTREVISION?=	0
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc/ \
		ftp://226.net120.skekraft.net/pcc/
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

PLIST_FILES=	bin/pcc libexec/ccom libexec/cpp \
		man/man1/pcc.1 man/man1/cpp.1 man/man1/ccom.1

pre-configure:
	${MKDIR} ${WRKSRC}/os/freebsd
	${LN} -sf ${FILESDIR}/*.h ${WRKSRC}/os/freebsd

.include <bsd.port.mk>
