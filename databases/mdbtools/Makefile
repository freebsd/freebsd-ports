# New ports collection makefile for:	mdbtools
# Date created:				25 April 2001
# Whom:	      				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	mdbtools
PORTVERSION=	0.5
PORTREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk	# To build man-pages

USE_BISON=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO
MAN1=		mdb-ver.1 mdb-tables.1 mdb-schema.1 mdb-sql.1 mdb-export.1

.if defined(WITH_GNOME) || exists(${X11BASE}/libdata/pkgconfig/libgnomeui-2.0.pc)
USE_X_PREFIX=	yes
USE_GNOME+=	gnomeprefix gnomehack libgnomeui
PLIST_SUB+=	GNOME:=""
PKGNAMESUFFIX=	-gnome
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(srcdir)/$$<|$$(srcdir)/$$>|g' ${WRKSRC}/doc/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}  ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
