# New ports collection makefile for:	mdbtools
# Date created:				25 April 2001
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mdbtools
PORTVERSION=	0.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO INSTALL

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e "s|glib-config|${GLIB_CONFIG}|g"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}  ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
