# ex:ts=8
# Ports collection makefile for:  pcc
# Date created:			  Mon Sept 17, 2007
# Whom:				  David O'Brien (obrien@NUXI.org)
#
# $FreeBSD$
#

PORTNAME=	pcc
DATESPEC=	090922
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

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${DATESPEC}
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	YACC=${YACC}
USE_GMAKE=	yes

MAN1=		pcc.1 cpp.1 ccom.1
PLIST_FILES=	bin/pcc libexec/ccom libexec/cpp

OSVERMAJOR=${OSREL:C/\.[0-9.]*//}

pre-configure:
	${MKDIR} ${WRKSRC}/os/freebsd
	${CP} ${FILESDIR}/*.h ${WRKSRC}/os/freebsd
	${REINPLACE_CMD} -e "s,%%OSVERMAJOR%%,${OSVERMAJOR}," \
		${WRKSRC}/os/freebsd/ccconfig.h

.include <bsd.port.mk>
