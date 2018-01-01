# Created by: Christopher Elkins <chrise@scardini.com>
# $FreeBSD$

PORTNAME=	nickle
PORTVERSION=	2.81
CATEGORIES=	lang
MASTER_SITES=	http://www.nickle.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Numeric-oriented programming language

LICENSE=	MIT

USES=		gmake ncurses readline
GNU_CONFIGURE=	yes

# Nickle now has bindings which are likely to pull in libraries that need
# libpthread.  Link to it now explicitly, or it wouldn't work at runtime.
LDFLAGS+=	-pthread

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|examples|| ; s| -O2||' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${FIND} . ! \( -name "*Makefile*" -or \
		-name "*.sgml" \) | ${CPIO} -pdm -L \
		-R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR})
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} \
		${SHAREMODE}

.include <bsd.port.mk>
