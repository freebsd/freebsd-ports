PORTNAME=	lnphost
PORTVERSION=	1.0a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lego RCX iinfrared communication API
WWW=		https://sourceforge.net/projects/lnphost/?source=directory/

LICENSE=	GPLv2

USES=		zip gmake
WRKSRC=		${WRKDIR}/lnphost
CFLAGS+=	-DHAVE_STRING_H

PLIST_FILES=	bin/lnpdump \
		lib/lnphost.a \
		include/lnphost.h \
		share/man/man1/lnpdump.1.gz

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

# Use system getopt
post-patch:
	${RM} ${WRKSRC}/Include/getopt.h ${WRKSRC}/Modules/getopt.c

.include <bsd.port.mk>
