# New ports collection makefile for:	erlslang
# Date Created:				18 July 2003
# Whom:				 	cpressey@catseye.mb.ca
#
# $FreeBSD$
#

PORTNAME=	erlslang
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.erlang.org/contrib/ \
		http://erlang.stacken.kth.se/contrib/ \
		http://www.csd.uu.se/ftp/mirror/erlang/contrib/ \
		http://www.serc.rmit.edu.au/mirrors/ose_mirror/contrib/
DISTNAME=	slang-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLang binding for Erlang/OTP

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=${WRKSRC}/config

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-build:
	@${RM} -r ${WRKSRC}/*/CVS
	@${RM} -r ${WRKSRC}/*/.cvsignore
	@${RM} -r ${WRKSRC}/*/.empty
	@${RM} -r ${WRKSRC}/*/Makefile
	@${RM} -r ${WRKSRC}/*/*.orig

do-install:
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${DISTNAME}
	@${CP} -r ${WRKSRC}/c_src ${PREFIX}/lib/erlang/lib/${DISTNAME}/c_src
	@${CP} -r ${WRKSRC}/demo  ${PREFIX}/lib/erlang/lib/${DISTNAME}/demo
	@${CP} -r ${WRKSRC}/ebin  ${PREFIX}/lib/erlang/lib/${DISTNAME}/ebin
	@${CP} -r ${WRKSRC}/priv  ${PREFIX}/lib/erlang/lib/${DISTNAME}/priv
	@${CP} -r ${WRKSRC}/src   ${PREFIX}/lib/erlang/lib/${DISTNAME}/src
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/slang

.include <bsd.port.post.mk>
