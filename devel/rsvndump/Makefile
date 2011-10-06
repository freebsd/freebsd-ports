# New ports collection makefile for:	rsvndump
# Date created:		2008-10-12
# Whom:			glarkin
#
# $FreeBSD$
#

PORTNAME=	rsvndump
PORTVERSION=	0.5.6
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

.if !defined(NOPORTDOCS)
MAN1=		rsvndump.1
.endif
PLIST_FILES+=	bin/rsvndump

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700041
LDFLAGS+=	${PTHREAD_LIBS}
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
CONFIGURE_ARGS+=--enable-man
.else
CONFIGURE_ARGS+=--disable-man
.endif

BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.include <bsd.port.post.mk>
