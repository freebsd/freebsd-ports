# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR= pgadmin3/release/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx=${X11BASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

POSTGRESQL_PORT?=	databases/postgresql7

post-patch:
	@${FIND} ${WRKSRC}/src \( -name '*.cpp' -or -name '*.h' \) -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's,wxNotifyEvent,wxCommandEvent,g'

.include <bsd.port.pre.mk>

.if defined(WITH_UNICODE)
.if ${OSVERSION} < 500000
IGNORE=		Systems prior to FreeBSD 5.0 currently out of support
.else
LIB_DEPENDS+=	wx_gtk2u_stc-2.5.3:${PORTSDIR}/x11-toolkits/wxgtk2-unicode-contrib-devel
CONFIGURE_ARGS+=--with-wx-config=wxgtk2u-2.5-config
.endif
.else
LIB_DEPENDS+=	wx_gtk2_stc-2.5.3:${PORTSDIR}/x11-toolkits/wxgtk2-contrib-devel
CONFIGURE_ARGS+=--with-wx-config=wxgtk2-2.5-config
.endif # WITH_UNICODE

.include <bsd.port.post.mk>
