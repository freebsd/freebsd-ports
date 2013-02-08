# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	VersionControl_SVN
PORTVERSION=	0.5.0
CATEGORIES=	devel pear

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Wrapper interface for the Subversion command-line client

USE_PHP=	yes
IGNORE_WITH_PHP=4

BUILD_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-XML_Parser>=1.3.4:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	pear>=1.9.4:${PORTSDIR}/devel/pear \
		pear-XML_Parser>=1.3.4:${PORTSDIR}/devel/pear-XML_Parser

CATEGORY=	VersionControl_SVN
FILES=		SVN.php \
		SVN/Command.php \
		SVN/Command/Add.php \
		SVN/Command/Blame.php \
		SVN/Command/Cat.php \
		SVN/Command/Changelist.php \
		SVN/Command/Checkout.php \
		SVN/Command/Cleanup.php \
		SVN/Command/Commit.php \
		SVN/Command/Copy.php \
		SVN/Command/Delete.php \
		SVN/Command/Diff.php \
		SVN/Command/Export.php \
		SVN/Command/Import.php \
		SVN/Command/Info.php \
		SVN/Command/List.php \
		SVN/Command/Log.php \
		SVN/Command/Merge.php \
		SVN/Command/Mkdir.php \
		SVN/Command/Move.php \
		SVN/Command/Propdel.php \
		SVN/Command/Propget.php \
		SVN/Command/Proplist.php \
		SVN/Command/Propset.php \
		SVN/Command/Resolved.php \
		SVN/Command/Revert.php \
		SVN/Command/Status.php \
		SVN/Command/Switch.php \
		SVN/Command/Update.php \
		SVN/Exception.php \
		SVN/Parser/Exception.php \
		SVN/Parser/XML.php \
		SVN/Parser/XML/Info.php \
		SVN/Parser/XML/List.php
EXAMPLES=	example1.php \
		example_tree.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
