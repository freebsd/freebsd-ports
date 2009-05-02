# ports collection makefile for:	gamin
# Date created:				24 March 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gamin/Makefile,v 1.6 2008/11/26 06:48:13 marcus Exp $
#

PORTNAME=	gamin
PORTVERSION=	0.1.10
PORTREVISION?=	2
CATEGORIES?=	devel
MASTER_SITES=	http://www.gnome.org/~veillard/gamin/sources/

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A file and directory monitoring system

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME?=	gnomehack _glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -DHAVE_LINUX" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

CONFLICTS=	fam-[0-9]*

GNU_CONFIGURE=	yes

.if !defined(GAMIN_SLAVE)
OPTIONS=	GAM_POLLER "Use gamin's poller instead of kqueue's" off
.endif

.include <bsd.port.pre.mk>

.if !defined(GAMIN_SLAVE)
.if defined(WITH_GAM_POLLER)
CPPFLAGS+=	-DUSE_GAMIN_POLLER=1
.endif
.endif

post-patch:
	@${REINPLACE_CMD} "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/server/gam_conf.c

.if !defined(GAMIN_SLAVE)
regression-test: build
	@${ECHO_MSG} "===> Running gamin regression tests"
	@(cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} tests)

post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
