PORTNAME=	cowsay
PORTVERSION=	3.04
DISTVERSIONPREFIX=	cowsay-
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Configurable talking characters in ASCII art

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5

USE_GITHUB=	yes

GH_ACCOUNT=	tnalpgge
GH_PROJECT=	rank-amateur-cowsay

NO_BUILD=	# defined

post-patch:
	@${REINPLACE_CMD} 's,usethisperl=.*,usethisperl=${PERL},' ${WRKSRC}/install.sh

do-install:
	cd ${WRKSRC}; ${SH} install.sh ${STAGEDIR}${PREFIX}
	# The sources have not had their version updated in the last release;
	#   normally this would be a patch (replacing the relevant "3.03" by
	#   something like %%PORTVERSION%%) and then a substitution, but there
	#   is no future release planned anyway.
	${SED} -i '' 's,3\.03,${PORTVERSION}_${PORTREVISION},' ${STAGEDIR}${PREFIX}/bin/cowsay
	# Since we called install.sh with a **stage** path, that is the path
	#   that gets edited into the script and manpage; remove the stage
	#   bit from both so that after installation cowsay uses, and the manpage
	#   mentions, the prefix path, not the stage path.
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/bin/cowsay
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/man/man1/cowsay.1
	${INSTALL_DATA} ${FILESDIR}/box.cow ${STAGEDIR}${PREFIX}/share/cows
	${INSTALL_DATA} ${FILESDIR}/jkh.cow ${STAGEDIR}${PREFIX}/share/cows
	${INSTALL_DATA} ${FILESDIR}/tux-stab.cow ${STAGEDIR}${PREFIX}/share/cows

.include <bsd.port.mk>
