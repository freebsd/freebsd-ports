# New ports collection makefile for:   freetds
# Date created:		02 Nov 1999
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	freetds
PORTVERSION=	0.53
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/freetds
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-tdsver=4.2
INSTALLS_SHLIB=	yes

.if defined(WITH_IODBC)
LIB_DEPENDS+=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-unixodbc=${LOCALBASE}
.endif

.if defined(WITH_IODBC) || defined(WITH_UNIXODBC)
USE_GLIB=	yes
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

post-patch:
.for file in configure include/tds.h.in src/tds/iconv.c
	@${PERL} -pi -e 's|<iconv.h>|<giconv.h>|g ; \
		 s|-liconv|-lgiconv|g' ${WRKSRC}/${file}
.endfor
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|/freetds.conf|/freetds.conf.dist|g ; \
		 s|glib-config|\$$\(GLIB_CONFIG\)|g ; \
		 s|-lglib|`\$$\(GLIB_CONFIG\) --libs glib`|g ; \
		 s| common.h||g'

post-install:
.if !exists(${PREFIX}/etc/freetds.conf)
	@${CP} ${PREFIX}/etc/freetds.conf.dist ${PREFIX}/etc/freetds.conf
.endif
	@${MKDIR} ${PREFIX}/etc/freetds
	${INSTALL_DATA} ${WRKSRC}/interfaces ${PREFIX}/etc/freetds

.include <bsd.port.mk>
