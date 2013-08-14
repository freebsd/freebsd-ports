# Created by: David O'Brien (obrien@NUXI.org)
# $FreeBSD$

PORTNAME=	pcc
PORTVERSION=	1.0.0
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-releases/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/ \
		ftp://226.net120.skekraft.net/pcc-releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	joel@FreeBSD.org
COMMENT=	The Portable C Compiler

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=${YACC}
USES=		gmake

MAKE_JOBS_UNSAFE=yes

MAN1=		ccom.1 cpp.1 pcc.1
PLIST_FILES=	bin/pcc libexec/ccom libexec/cpp

pre-configure:
	${MKDIR} ${WRKSRC}/os/freebsd
	${CP} ${FILESDIR}/*.h ${WRKSRC}/os/freebsd
	${REINPLACE_CMD} -e "s,%%OSVERMAJOR%%,${OSREL:R}," \
		${WRKSRC}/os/freebsd/ccconfig.h

.include <bsd.port.mk>
