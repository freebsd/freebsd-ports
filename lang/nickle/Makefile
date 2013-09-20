# Created by: Christopher Elkins <chrise@scardini.com>
# $FreeBSD$

PORTNAME=	nickle
PORTVERSION=	2.77
CATEGORIES=	lang
MASTER_SITES=	http://www.nickle.org/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A numeric oriented programming language

LICENSE=	MIT

OPTIONS_DEFINE=	EXAMPLES

USES=		ncurses
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

# Nickle now has bindings which are likely to pull in libraries that need
# libpthread.  Link to it now explicitly, or it wouldn't work at runtime.
LDFLAGS+=	${PTHREAD_LIBS}

MAN1=		nickle.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|examples|| ; \
		 s| -O2||' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${FIND} . ! \( -name "*Makefile*" -or \
		-name "*.sgml" \) | ${CPIO} -pdm -L \
		-R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR})
	@${FIND} ${EXAMPLESDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
