# New ports collection makefile for:	rsvndump
# Date created:		2008-10-12
# Whom:			glarkin
#
# $FreeBSD$
#

PORTNAME=	rsvndump
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Remote Subversion repository dumpfile generator

GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_FILES+=		share/locale/de/LC_MESSAGES/rsvndump.mo
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
CONFIGURE_ARGS+=	--enable-man \
			--with-svn=${LOCALBASE}

MAN1=		rsvndump.1
PLIST_FILES+=	bin/rsvndump

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700041
CONFIGURE_ENV+=	LDFLAGS=${PTHREAD_LIBS}
.endif

BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto

.if !exists(${APR_APU_DIR}/${APR_CONFIG})
BUILD_DEPENDS+=	apr-1-config:${PORTSDIR}/devel/apr1
.endif

BUILD_DEPENDS+=	subversion>=0:${PORTSDIR}/devel/subversion
.include <bsd.port.post.mk>
