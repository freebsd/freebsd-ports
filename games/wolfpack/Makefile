# Created by: Daniel O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	wolfpack
PORTVERSION=	4.3.32
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	empserver/${DISTNAME}
DISTNAME=	empire-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Long term multiplayer strategy game

MAKEFILE=	GNUmakefile
USES=		gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
BINDIR=		${PREFIX}/lib/${PORTNAME}
VARDIR=		${PREFIX}/var/${PORTNAME}
CONFIGURE_ARGS+=	--bindir=${BINDIR} --sbindir=${BINDIR}

CONFLICTS_INSTALL=	empire-[0-9]*

USERS=		wolfpack
GROUPS=		wolfpack

USE_RC_SUBR=	wolfpack
SUB_FILES+=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e '/^econfig/,/^$$/s|/empire|/${PORTNAME}|' \
		${WRKSRC}/Make.mk ${WRKSRC}/sources.mk
.if ${ARCH} == "sparc64"
	${REINPLACE_CMD} -e '/ucontext\.h/ { h; s|ucontext|sys/types|; G; }' \
		${WRKSRC}/src/lib/lwp/lwpint.h
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DATADIR}
	${LN} -s ${BINDIR}/emp_server ${STAGEDIR}${PREFIX}/bin/emp_server
	${LN} -s ${BINDIR}/empire ${STAGEDIR}${PREFIX}/bin/emp_client
	${STAGEDIR}${PREFIX}/lib/wolfpack/pconfig > \
		${STAGEDIR}${ETCDIR}/econfig.orig

.include <bsd.port.post.mk>
