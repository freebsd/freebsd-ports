# New ports collection makefile for:	tora
# Date created:				03 January 2002
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	tora
PORTVERSION=	1.2.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_QT_VER=	2

QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=	--with-gcc=${CC} \
			--with-qt-moc=${MOC} \
			--with-qt-uic=${X11BASE}/bin/uic \
			--with-qt-libs=${X11BASE}/lib \
			--with-qt-include=${X11BASE}/include/qt2 \
			--without-oracle \
			--with-mysql-include=${LOCALBASE}/include/mysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql

DOCS=	BUGS LICENSE NEWS README TODO

post-patch:
	${PERL} -pi -e \
		"s@^(my $$Libs.*)-lpthread -ldl\";\$$@\1 ${PTHREAD_LIBS}\";@; \
		s@^(CFLAGS_GLOB.*)@\1 ${CFLAGS} ${PTHREAD_CFLAGS}@" \
	${WRKSRC}/configure.pl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tora-mono ${PREFIX}/bin/tora
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${CP} -R ${WRKSRC}/help ${DOCSDIR}/
	${FIND} ${DOCSDIR} -type d -exec ${CHMOD} 755 {} \;
	${FIND} ${DOCSDIR} -type f -exec ${CHMOD} 644 {} \;
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
