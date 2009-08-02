# New ports collection makefile for:		cacao
# Date created:					2005-04-28
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	cacao
PORTVERSION=	0.98
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	http://www.complang.tuwien.ac.at/cacaojvm/download/cacao-${PORTVERSION}/

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	JIT compiler for JAVA

BUILD_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath

USE_BZIP2=	yes
USE_AUTOTOOLS=	libltdl
USE_JAVA=	yes
JAVA_VERSION=	1.4+
GNU_CONFIGURE=	yes
MAN1=		cacao.1
CONFIGURE_ARGS+=	--with-classpath-prefix=${LOCALBASE}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
IGNORE=		unsupported architecture
.endif

post-patch:
	${REINPLACE_CMD} -e "s, man,," ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/cacao.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
