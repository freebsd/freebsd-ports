# Created by: jesse@cs.uni-magdeburg.de
# $FreeBSD$

PORTNAME=	tmake
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://ftp.trolltech.com/freebies/tmake/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely portable perl-based make utility

NO_BUILD=	yes
REINPLACE_ARGS=	-i ''
USES=		perl5 shebangfix

SHEBANG_FILES=	bin/progen bin/tmake

post-patch:
	@${RM} ${WRKSRC}/bin/tmake.orig ${WRKSRC}/lib/unix/generic.t.orig
	@${REINPLACE_CMD} \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e '/^TMAKE_CFLAGS_RELEASE/ s| -O[0-9]||' \
			${WRKSRC}/lib/freebsd-g++/tmake.conf

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/bin/ && ${INSTALL_SCRIPT} progen tmake ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	@${ECHO_MSG}
	@${ECHO_MSG} "Make sure to set your TMAKEPATH environment variable"
	@${ECHO_MSG} "to ${DATADIR}/freebsd-g++."
	@${ECHO_MSG}

.include <bsd.port.mk>
