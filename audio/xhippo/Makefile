# New ports collection makefile for:	xhippo
# Date created:				16 March 1999
# Whom:					Rod Taylor <rod@zort.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xhippo
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Generic music player for UNIX systems

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_GNOME=	gtk12
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		ChangeLog gnu-xhippo.html screenshot.jpeg xhippo.html.gz \
		xhippo.info.gz xhippo.ps.gz xhippo.sgml xhippo.txt.gz

MAN1=	xhippo.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS+=	--with-gnome
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/xhippo.config ${PREFIX}/etc/xhippo.config.default
.if !exists(${PREFIX}/etc/xhippo.config)
	${CP} ${PREFIX}/etc/xhippo.config.default ${PREFIX}/etc/xhippo.config
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
