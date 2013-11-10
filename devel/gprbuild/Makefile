# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gprbuild
PORTVERSION=	${SNAPSHOT}
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	gprbuild-gpl-2012-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore multi-language software build tool

LICENSE=	GPLv3

BUILD_DEPENDS+=	xmlada>=3.2:${PORTSDIR}/textproc/xmlada

EXAMPLESDIR=	share/examples/gprbuild
DOCSDIR=	share/doc/gprbuild
WRKSRC=		${WRKDIR}/gprbuild-2012-src
SNAPSHOT=	20120510
GNU_CONFIGURE=	yes
USES=		ada gmake

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:L}${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,@AUXPREFIX@,${PREFIX}/gcc-aux," \
	  ${WRKSRC}/share/gprconfig/compilers.xml

post-install:
	cd ${STAGEDIR}${PREFIX}; ${FIND} share -type d -empty | \
	  ${SORT} -dr | ${XARGS} ${RMDIR}

.include <bsd.port.post.mk>
