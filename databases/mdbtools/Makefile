# New ports collection makefile for:	mdbtools
# Date created:				25 April 2001
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mdbtools
PORTVERSION=	0.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk	# To build man-pages

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO
MAN1=		mdb-ver.1 mdb-tables.1 mdb-schema.1 mdb-sql.1 mdb-export.1

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e "s|glib-config|${GLIB_CONFIG}|g" \
		-e "s|@GLIB_CFLAGS@|`${GLIB_CONFIG} --cflags`|g" \
		-e "s|@GLIB_LIBS@|`${GLIB_CONFIG} --libs`|g"
	${REINPLACE_CMD} -e 's|$$(srcdir)/$$<|$$(srcdir)/$$>|g' ${WRKSRC}/doc/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}  ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
