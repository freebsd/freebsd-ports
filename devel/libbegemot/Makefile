PORTNAME=	libbegemot
PORTVERSION=	1.11
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/ \
		http://m1cro.me/ports/distfiles/libbegemot/

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Function library for begemot tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libbegemot.so

.include <bsd.port.mk>
