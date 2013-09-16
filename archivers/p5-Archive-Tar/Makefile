# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	Archive-Tar
PORTVERSION=	1.92
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl module for creation and manipulation of tar files

RUN_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String

USES=		perl5
USE_PERL5=	configure

MAN3=		Archive::Tar.3 Archive::Tar::File.3

OPTIONS_DEFINE=	TEXTDIFF
TEXTDIFF_DESC=	"Text::Diff support for ptardiff"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEXTDIFF}
RUN_DEPENDS+=	p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/5.009/5.666/' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
