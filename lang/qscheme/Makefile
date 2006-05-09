# New ports collection makefile for:	qscheme
# Date created:			6 Dec 2001
# Whom:				erik@smluc.org
#
# $FreeBSD$
#

PORTNAME=	qscheme
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.sof.ch/dan/qscheme/files/

MAINTAINER=	erik@smluc.org
COMMENT=	A small and fast Scheme interpreter

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall\
		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	getline:${PORTSDIR}/devel/libgetline

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

CONFIGURE_ARGS=	--with-pcre-dir=${LOCALBASE}/lib \
		--with-pcre-inc=${LOCALBASE}/include \
		--with-avcall-dir=${LOCALBASE}/lib \
		--with-avcall-inc=${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} \
		-e "s,^LIBS = @LIBS@,& ${PTHREAD_LIBS} -L${LOCALBASE}/lib -lgetline," \
		-e "s,^CFLAGS = @CFLAGS@,& ${PTHREAD_CFLAGS}," \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} \
		-e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 or ia64"
.endif

.if ${OSVERSION} >= 500000
BUILD_DEPENDS+=	${LOCALBASE}/include/gmp.h:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+=	--with-gmp-dir=${LOCALBASE}/lib \
		--with-gmp-inc=${LOCALBASE}/include
.endif

.include <bsd.port.post.mk>
