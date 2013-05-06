# Created by: glarkin
# $FreeBSD$

PORTNAME=	rsvndump
PORTVERSION=	0.5.8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Remote Subversion repository dumpfile generator

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_FILES+=		share/locale/de/LC_MESSAGES/rsvndump.mo
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
CONFIGURE_ARGS+=	--enable-man \
			--with-svn=${LOCALBASE}

.if ${PORT_OPTIONS:MDOCS}
MAN1=		rsvndump.1
.endif
PLIST_FILES+=	bin/rsvndump

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
CONFIGURE_ARGS+=--enable-man
.else
CONFIGURE_ARGS+=--disable-man
.endif

BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.include <bsd.port.mk>
