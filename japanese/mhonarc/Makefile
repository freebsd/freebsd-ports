# New ports collection makefile for:	MHonArc
# Version required:		2.3.3
# Date created:			17 March 1999
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	MHonArc2.3.3
PKGNAME=	ja-mhonarc-2.3.3
CATEGORIES=	japanese www
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/ \
		ftp://contrib.redhat.com/noarch/ \
		ftp://ftp.plig.org/pub/CPAN/authors/id/EHOOD/ \
		http://www.perl.com/CPAN/authors/id/EHOOD/ \
		http://www.shiratori.riec.tohoku.ac.jp/~p-katoh/Hack/Docs/mhonarc-jp/ \
		http://www.freebsd.org/~flathill/distfiles/
DISTFILES=	MHonArc2.3.3.tar.gz iso2022.pl

MAINTAINER=	flathill@FreeBSD.org

EXTRACT_ONLY=	MHonArc2.3.3.tar.gz
Y2K=		http://www.oac.uci.edu/indiv/ehood/MHonArc/doc/faq/general.html#y2k

USE_PERL5=	Yes
NO_BUILD=	Yes

.include <bsd.port.pre.mk>

pre-install:
	${CP} ${DISTDIR}/iso2022.pl ${WRKSRC}/lib/

do-install:
	cd ${WRKSRC} && ${PERL5} install.me -prefix ${PREFIX} -batch
	${MKDIR} ${PREFIX}/share/examples/MHonArc
	${INSTALL_DATA} ${FILESDIR}/mhonarc.rc.sample ${PREFIX}/share/examples/MHonArc/

post-install:
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
