# Created by: glarkin

PORTNAME=	rsvndump
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remote Subversion repository dumpfile generator

LICENSE=	GPLv2

USES=		bdb
LIB_DEPENDS=	libsvn_client-1.so:devel/subversion \
		libgdbm.so:databases/gdbm \
		libexpat.so:textproc/expat2 \
		libapr-1.so:devel/apr1

OPTIONS_DEFINE=	DOCS NLS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-svn=${LOCALBASE}

PLIST_FILES=	bin/rsvndump

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
DOCS_PLIST_FILES=	man/man1/rsvndump.1.gz
DOCS_CONFIGURE_ENABLE=	man

NLS_USES=		gettext
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/rsvndump.mo
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
