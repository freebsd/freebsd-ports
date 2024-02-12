PORTNAME=	rsvndump
DISTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Remote Subversion repository dumpfile generator
WWW=		http://rsvndump.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libexpat.so:textproc/expat2 \
		libgdbm.so:databases/gdbm
.if ${WITH_SUBVERSION_VER:U} == LTS
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion-lts
.else
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion
.endif

USES=		bdb:18 gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-svn=${LOCALBASE}

PLIST_FILES=	bin/rsvndump

OPTIONS_DEFINE=	DOCS NLS

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
DOCS_CONFIGURE_ENABLE=	man
DOCS_PLIST_FILES=	share/man/man1/rsvndump.1.gz

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/rsvndump.mo

.include <bsd.port.mk>
