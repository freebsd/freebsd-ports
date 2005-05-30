# Ports collection makefile for:  pear-Net_SmartIRC
# Date created:			  30 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Net_SmartIRC
PORTVERSION=	1.0.0
CATEGORIES=	irc www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class for communication with IRC networks

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		SmartIRC/defines.php SmartIRC/irccommands.php \
		SmartIRC/messagehandler.php SmartIRC.php
DOCS=		DOCUMENTATION HOWTO HTML/classtrees_Net_SmartIRC.html \
		HTML/elementindex.html HTML/elementindex_Net_SmartIRC.html \
		HTML/errors.html HTML/index.html HTML/li_Net_SmartIRC.html \
		HTML/ric_CHANGELOG.html HTML/ric_README.html \
		HTML/media/background.png HTML/media/empty.png \
		HTML/media/style.css HTML/media/TreeMenu.js \
		HTML/media/images/blank.png HTML/media/images/checkerboard.gif \
		HTML/media/images/Class.gif HTML/media/images/classFolder.gif \
		HTML/media/images/Constant.gif HTML/media/images/Constants.gif \
		HTML/media/images/Constructor.gif HTML/media/images/Destructor.gif \
		HTML/media/images/Disk.gif HTML/media/images/error.gif \
		HTML/media/images/file.png HTML/media/images/FolderClosed.gif \
		HTML/media/images/foldericon.png HTML/media/images/FolderOpened.gif \
		HTML/media/images/Functions.gif HTML/media/images/GhostClass.gif \
		HTML/media/images/I.png HTML/media/images/L.png \
		HTML/media/images/leftbg.gif HTML/media/images/Lminus.png \
		HTML/media/images/Lplus.png HTML/media/images/minus.gif \
		HTML/media/images/msgError.gif HTML/media/images/msgFatalError.gif \
		HTML/media/images/msgHint.gif HTML/media/images/msgInformation.gif \
		HTML/media/images/msgWarning.gif \
		HTML/media/images/openfoldericon.png HTML/media/images/pearlogo.gif \
		HTML/media/images/plus.gif HTML/media/images/PrivateDataMember.gif \
		HTML/media/images/PrivateMethod.gif \
		HTML/media/images/PrivateProperty.gif \
		HTML/media/images/ProtectedDataMember.gif \
		HTML/media/images/ProtectedMethod.gif \
		HTML/media/images/ProtectedProperty.gif \
		HTML/media/images/PublicDataMember.gif \
		HTML/media/images/PublicMethod.gif \
		HTML/media/images/PublicProperty.gif HTML/media/images/spacer.gif \
		HTML/media/images/spacer2.gif HTML/media/images/T.png \
		HTML/media/images/Tminus.png HTML/media/images/Tplus.png \
		HTML/media/images/Types.gif HTML/media/images/Variable.gif \
		HTML/media/images/Vars.gif HTML/media/images/TreeMenuJS/branch.gif \
		HTML/media/images/TreeMenuJS/branchbottom.gif \
		HTML/media/images/TreeMenuJS/branchtop.gif \
		HTML/media/images/TreeMenuJS/Class.gif \
		HTML/media/images/TreeMenuJS/classFolder.gif \
		HTML/media/images/TreeMenuJS/Disk.gif \
		HTML/media/images/TreeMenuJS/file.png \
		HTML/media/images/TreeMenuJS/folder.gif \
		HTML/media/images/TreeMenuJS/FolderOpened.gif \
		HTML/media/images/TreeMenuJS/Functions.gif \
		HTML/media/images/TreeMenuJS/line.gif \
		HTML/media/images/TreeMenuJS/linebottom.gif \
		HTML/media/images/TreeMenuJS/minus.gif \
		HTML/media/images/TreeMenuJS/minusbottom.gif \
		HTML/media/images/TreeMenuJS/minustop.gif \
		HTML/media/images/TreeMenuJS/plus.gif \
		HTML/media/images/TreeMenuJS/plusbottom.gif \
		HTML/media/images/TreeMenuJS/plustop.gif \
		HTML/media/lib/classTree.js HTML/media/lib/tab.webfx.css \
		HTML/media/lib/tabpane.js HTML/media/lib/ua.js \
		HTML/Net_SmartIRC/mybot.html HTML/Net_SmartIRC/Net_SmartIRC.html \
		HTML/Net_SmartIRC/Net_SmartIRC_actionhandler.html \
		HTML/Net_SmartIRC/Net_SmartIRC_base.html \
		HTML/Net_SmartIRC/Net_SmartIRC_channel.html \
		HTML/Net_SmartIRC/Net_SmartIRC_channeluser.html \
		HTML/Net_SmartIRC/Net_SmartIRC_data.html \
		HTML/Net_SmartIRC/Net_SmartIRC_Error.html \
		HTML/Net_SmartIRC/Net_SmartIRC_irccommands.html \
		HTML/Net_SmartIRC/Net_SmartIRC_ircuser.html \
		HTML/Net_SmartIRC/Net_SmartIRC_listenfor.html \
		HTML/Net_SmartIRC/Net_SmartIRC_messagehandler.html \
		HTML/Net_SmartIRC/Net_SmartIRC_timehandler.html \
		HTML/Net_SmartIRC/Net_SmartIRC_user.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example2_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example3_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example4_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example5_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example6_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example7_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_examples_example_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_SmartIRC_defines_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_SmartIRC_irccommands_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_SmartIRC_messagehandler_php.html \
		HTML/Net_SmartIRC/_SmartIRC-0.5.5_SmartIRC_php.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
