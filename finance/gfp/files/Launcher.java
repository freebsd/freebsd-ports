import SevenZip.LzmaAlone;
import com.sun.java.util.jar.pack.PackerImpl;
import com.sun.java.util.jar.pack.UnpackerImpl;
import java.io.*;
import java.lang.reflect.Method;
import java.util.Enumeration;
import java.util.Map;
import java.util.jar.JarInputStream;
import java.util.jar.JarOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/*
 * Created on 07/04/2003
 *
 * Swing Components - visit http://sf.net/projects/gfd
 *
 * Copyright (C) 2004  Igor Regis da Silva Sim\xf5es
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

public final class Launcher
{

    public Launcher(boolean flag, String s)
        throws IOException
    {
        unpacker = new UnpackerImpl();
        packer = new PackerImpl();
        System.out.println((new StringBuilder()).append("pack= ").append(flag).append(" file= ").append(s).toString());
        BufferedReader bufferedreader = null;
        try
        {
            bufferedreader = new BufferedReader(new FileReader(new File((new StringBuilder()).append(System.getProperty("user.dir")).append(File.separator).append("setup.dat").toString())));
        }
        catch(FileNotFoundException filenotfoundexception)
        {
            if(s == null)
                return;
        }
        if(flag)
        {
            if(s == null)
            {
                for(String s1 = ""; (s1 = bufferedreader.readLine()) != null;)
                    try
                    {
                        String as1[] = s1.split("@");
                        compactarArquivo(as1[0], as1[1]);
                    }
                    catch(IOException ioexception1)
                    {
                        System.out.println("*************************************************");
                        System.out.println((new StringBuilder()).append("Falha ao compactar: ").append(s1.substring(2)).toString());
                        System.out.println(ioexception1.getMessage());
                        System.out.println("*************************************************");
                    }

            } else
            {
                s = s.replace('\\', File.separatorChar).replace('/', File.separatorChar);
                System.out.println((new StringBuilder()).append("Vou compactar o arquivo: ").append(s).toString());
                try
                {
                    String as[] = new String[2];
                    if(s.indexOf(File.separator) != -1)
                    {
                        as[0] = s.substring(s.lastIndexOf(File.separator) - 1, s.length());
                        as[1] = s.substring(0, s.lastIndexOf(File.separator) + 1);
                    } else
                    {
                        as[0] = s;
                        as[1] = "";
                    }
                    if(!as[1].startsWith(File.separator))
                        as[1] = (new StringBuilder()).append(File.separator).append(as[1]).toString();
                    compactarArquivo(as[0], as[1]);
                }
                catch(IOException ioexception)
                {
                    System.out.println("*************************************************");
                    System.out.println((new StringBuilder()).append("Falha ao compactar: ").append(s).toString());
                    System.out.println(ioexception.getMessage());
                    System.out.println("*************************************************");
                }
            }
        } else
        {
            String s2 = "";
            do
            {
                String s3;
                if((s3 = bufferedreader.readLine()) == null)
                    break;
                try
                {
                    String as2[] = s3.split("@");
                    descompactarArquivo(as2[0], as2[1]);
                    if(as2[0].startsWith("z_"))
                        explodir(as2[0], as2[1]);
                }
                catch(IOException ioexception2)
                {
                    System.out.println("*************************************************");
                    System.out.println((new StringBuilder()).append("Fail on install file: ").append(s3.substring(2)).toString());
                    System.out.println(ioexception2.getMessage());
                    System.out.println("*************************************************");
                }
            } while(true);
            bufferedreader.close();
            (new File((new StringBuilder()).append(System.getProperty("user.dir")).append(File.separator).append("setup.dat").toString())).delete();
        }
        if(bufferedreader != null)
            bufferedreader.close();
    }

    private void descompactarArquivo(String s, String s1)
        throws IOException
    {
        String s2 = (new StringBuilder()).append(System.getProperty("user.dir")).append(s1).toString();
        try
        {
            LzmaAlone.main(new String[] {
                "d", (new StringBuilder()).append(s2).append(s).toString(), (new StringBuilder()).append(s2).append(s.substring(1)).toString()
            });
        }
        catch(Exception exception)
        {
            exception.printStackTrace();
        }
        JarOutputStream jaroutputstream = new JarOutputStream(new FileOutputStream(new File((new StringBuilder()).append(s2).append(s.substring(2)).toString())));
        FileInputStream fileinputstream = new FileInputStream((new StringBuilder()).append(s2).append(s.substring(1)).toString());
        unpacker.unpack(fileinputstream, jaroutputstream);
        jaroutputstream.flush();
        fileinputstream.close();
        jaroutputstream.close();
        for(File file = new File((new StringBuilder()).append(s2).append(s.substring(1)).toString()); !file.delete() && file.exists(); System.out.println((new StringBuilder()).append("Tentando deletar ").append(s2).append("_").append(s).toString()));
        for(File file1 = new File((new StringBuilder()).append(s2).append(s).toString()); !file1.delete() && file1.exists(); System.out.println((new StringBuilder()).append("Tentando deletar ").append(s2).append(s).toString()));
    }

    private void compactarArquivo(String s, String s1)
        throws IOException
    {
        String s2 = s1;
        if(!(new File(s2)).exists() || s2.equals(File.separator))
            s2 = (new StringBuilder()).append(System.getProperty("user.dir")).append(s1).toString();
        String s3 = s.substring(0, 1).toLowerCase();
        s = s.substring(2);
        System.out.println((new StringBuilder()).append("Caminho completo ").append((new StringBuilder()).append(s2).append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar)).toString());
        java.util.SortedMap sortedmap = packer.properties();
        sortedmap.put("pack.deflate.hint", "false");
        sortedmap.put("pack.effort", "9");
        sortedmap.put("pack.keep.file.order", "false");
        sortedmap.put("pack.modification.time", "latest");
        sortedmap.put("pack.segment.limit", "1500000");
        sortedmap.put("pack.unknown.attribute", "strip");
        if(s.toLowerCase().indexOf("gf") != -1 || s.toLowerCase().indexOf("visa") != -1)
        {
            System.out.println("Pack COM debug info");
            sortedmap.put("pack.code.attribute.LineNumberTable", "pass");
            sortedmap.put("pack.code.attribute.LocalVariableTable", "pass");
            sortedmap.put("pack.class.attribute.SourceFile", "pass");
        } else
        {
            System.out.println("Pack SEM debug info");
            sortedmap.put("pack.code.attribute.LineNumberTable", "strip");
            sortedmap.put("pack.code.attribute.LocalVariableTable", "strip");
            sortedmap.put("pack.class.attribute.SourceFile", "strip");
        }
        System.out.println((new StringBuilder()).append(s2).append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar));
        System.out.println((new StringBuilder()).append(s2).append("_").append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar));
        JarInputStream jarinputstream = new JarInputStream(new FileInputStream((new StringBuilder()).append(s2).append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar)));
        FileOutputStream fileoutputstream = new FileOutputStream((new StringBuilder()).append(s2).append("_").append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar));
        packer.pack(jarinputstream, fileoutputstream);
        jarinputstream.close();
        fileoutputstream.flush();
        fileoutputstream.close();
        try
        {
            LzmaAlone.main(new String[] {
                "e", "-a9", (new StringBuilder()).append(s2).append("_").append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar), (new StringBuilder()).append(s2).append(s3.startsWith("z") ? "z_" : "__").append(s).toString().replace('\\', File.separatorChar).replace('/', File.separatorChar)
            });
        }
        catch(Exception exception)
        {
            exception.printStackTrace();
            System.exit(-1);
        }
        for(File file = new File((new StringBuilder()).append(s2).append("_").append(s).toString().replace("\\", File.separator).replace("/", File.separator)); !file.delete() && file.exists();)
        {
            System.out.println((new StringBuilder()).append("Tentando deletar ").append(file.getAbsolutePath()).toString());
            try
            {
                Thread.sleep(1000L);
            }
            catch(InterruptedException interruptedexception)
            {
                interruptedexception.printStackTrace();
            }
        }

        for(File file1 = new File((new StringBuilder()).append(s2).append(s).toString().replace("\\", File.separator).replace("/", File.separator)); !file1.delete() && file1.exists();)
        {
            System.out.println((new StringBuilder()).append("Tentando deletar ").append(file1.getAbsolutePath()).toString());
            try
            {
                Thread.sleep(1000L);
            }
            catch(InterruptedException interruptedexception1)
            {
                interruptedexception1.printStackTrace();
            }
        }

    }

    private void explodir(String s, String s1)
        throws IOException
    {
        File file = new File((new StringBuilder()).append(System.getProperty("user.dir")).append(s1).append(s.substring(2)).toString());
        Object obj = null;
        ZipFile zipfile = new ZipFile(file);
        for(Enumeration enumeration = zipfile.entries(); enumeration.hasMoreElements();)
        {
            ZipEntry zipentry = (ZipEntry)enumeration.nextElement();
            if(zipentry.getSize() == 0L)
            {
                (new File((new StringBuilder()).append(System.getProperty("user.dir")).append(s1).append(File.separator).append(zipentry.getName().replace('/', '\\')).toString())).mkdirs();
            } else
            {
                DataInputStream datainputstream = new DataInputStream(zipfile.getInputStream(zipentry));
                byte abyte0[] = new byte[datainputstream.available()];
                datainputstream.readFully(abyte0);
                datainputstream.close();
                File file1 = new File((new StringBuilder()).append(System.getProperty("user.dir")).append(s1).append(File.separator).append(zipentry.getName().replace('/', '\\')).toString());
                if(!file1.getParentFile().exists())
                    file1.getParentFile().mkdirs();
                file1.createNewFile();
                FileOutputStream fileoutputstream = new FileOutputStream(file1);
                fileoutputstream.write(abyte0);
                fileoutputstream.flush();
                fileoutputstream.close();
            }
        }

        zipfile.close();
        file.delete();
    }

    public static void main(String args[])
    {
        File file = new File((new StringBuilder()).append(System.getProperty("user.dir")).append(File.separator).append("running.lck").toString());
        if(file.exists())
            return;
        try
        {
            file.createNewFile();
        }
        catch(IOException ioexception)
        {
            ioexception.printStackTrace();
        }
        file.deleteOnExit();
        if(args == null || args.length == 0)
        {
            Launcher launcher = null;
            try
            {
                launcher = new Launcher(false, null);
            }
            catch(IOException ioexception3)
            {
                ioexception3.printStackTrace();
            }
        } else
        if(!(new File(args[0])).exists() && !args[0].startsWith("__"))
            try
            {
                new Launcher(true, null);
            }
            catch(IOException ioexception1)
            {
                ioexception1.printStackTrace();
            }
        else
            try
            {
                new Launcher(true, args[0]);
            }
            catch(IOException ioexception2)
            {
                ioexception2.printStackTrace();
            }
    }

    private UnpackerImpl unpacker;
    private PackerImpl packer;
}
