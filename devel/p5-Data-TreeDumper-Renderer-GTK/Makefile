PORTNAME=	Data-TreeDumper-Renderer-GTK
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GTK renderer for Data::TreeDumper
WWW=		https://metacpan.org/release/Data-TreeDumper-Renderer-GTK

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-TreeDumper>=0:devel/p5-Data-TreeDumper \
		p5-Gtk3>=0:x11-toolkits/p5-Gtk3

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	gtk_test.pl
NO_ARCH=	yes

.include <bsd.port.mk>
